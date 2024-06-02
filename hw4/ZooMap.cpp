/*
 * @author Mehmet Akif Sahin 22203673
 * @date 16 December 2023
 */
#include "ZooMap.h"
#include "MyStack.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
 
using namespace std;

ZooMap::ZooMap(const string cageFile, const string zooFile) {
	ifstream nodes(cageFile);
	ifstream edges(zooFile);
	int cageCount = 0;
	int edgeCount = 0;

	string line;
	while (getline(nodes, line)){
		cageCount++;
		int semicolonIndex = line.find(';');
		string cageName = line.substr(0,semicolonIndex);
		double cageWeight = std::stod(line.substr(semicolonIndex+1));
		Cage cage(cageName, cageWeight);
		cages.insert(cage);
	}

	while (getline(edges, line)){
		edgeCount++;
		int semicolonIndex = line.find(';');
		string firstName = line.substr(0,semicolonIndex);
		string secondName = line.substr(semicolonIndex+1);
		int indexOfFirst;
		int indexOfSecond;

		for (int i = 0; i < cages.getLength(); i++) {
			if (cages[i]->getName() == firstName) {
				indexOfFirst = i;
			}
			if (cages[i]->getName() == secondName) {
				indexOfSecond = i;
			}
		}
		cages[indexOfFirst]->getAdjacentCages().insert(indexOfSecond);
	}
	cout << cageCount << " cages and " << edgeCount << " connections have been loaded." << endl;
}

ZooMap::~ZooMap() {

}

void ZooMap::displayAllCages() const {
	int cageCount = cages.getLength();
	cout << "The cages in the zoo are:" << endl;
	for (int i = 0; i < cageCount; i++) {
		cout << cages[i]->getName() << ",";
		if (i != cageCount - 1) cout << " ";
	}
	cout << endl;
}

void ZooMap::displayAdjacentCages(const string cageName) const {
	Cage* cage = cages[cages.find(cageName)];
	cout << "The cages adjacent to " << cageName << " are:" << endl;
	cout << cageName << " ->";
	int cageCount = cage->getAdjacentCages().getLength();
	for (int i = 0; i < cageCount; i++) {
		int cageIndex = *cage->getAdjacentCages()[i];
		cout << " " << cages[cageIndex]->getName() << ",";
	}
	cout << endl;
}

void ZooMap::displayZooMap() const {
	cout << "The whole zoo map is:" << endl;
	int parentCageCount = cages.getLength();
	for (int i = 0; i < parentCageCount; i++) {
		Cage* cage = cages[i];
		cout << cage->getName() << " ->";
		int childCageCount = cage->getAdjacentCages().getLength();
		for (int j = 0; j < childCageCount; j++) {
			int cageIndex = *cage->getAdjacentCages()[j];
			cout << " " << cages[cageIndex]->getName() << ",";
		}
		cout << endl;
	}
}

void ZooMap::findSafestPath(const string startCage, const string endCage) {
	int cageCount = cages.getLength();
	bool* visited = new bool[cageCount];
	for (int i = 0; i < cageCount; i++){
		visited[i] = false;
	}

	int* indexLeft = new int[cageCount];
	for (int i = 0; i < cageCount; i++) {
		indexLeft[i] = 0;
	}

	int firstCage = cages.find(startCage);
	visited[firstCage] = true;
	MyStack<int> cageStack;
	MyStack<int> safestPath;
	double weightProduct = 1.0;
	double safestWeight = 0.0;

	cageStack.push(firstCage);
	weightProduct *= cages[firstCage]->getWeight();

	while (!cageStack.isEmpty()) {
		int cage = cageStack.peek();
		bool found = false;
		if (cages[cage]->getName() == endCage) {
			if (weightProduct > safestWeight) {
				safestWeight = weightProduct;
				safestPath = cageStack;
			}
			found = true;
		}
		while (indexLeft[cage] < cages[cage]->getAdjacentCages().getLength() &&
			visited[*cages[cage]->getAdjacentCages()[indexLeft[cage]]]) {
			indexLeft[cage]++;
		}
		if (indexLeft[cage] == cages[cage]->getAdjacentCages().getLength() // this means that all of the adjacent cages of the cage at the top of the stack is visited
			|| found) {
			visited[cage] = false;
			cageStack.pop();
			indexLeft[cage] = 0;
			weightProduct /= cages[cage]->getWeight();
		} else {
			int cageIndex = *cages[cage]->getAdjacentCages()[indexLeft[cage]];
			visited[cageIndex] = true;
			cageStack.push(cageIndex);
			indexLeft[cage]++;
			weightProduct *= cages[cageIndex]->getWeight();
		}
		//cageStack.printStack();
	}

	if (safestPath.getSize() == 0) {
		cout << "No path exists from " << startCage << " to " << endCage << "." << endl;
	} else {
		cout << "Safest path from " << startCage << " to " << endCage << " is:" << endl;
		cout << startCage;
		safestPath.pop();
		while (!safestPath.isEmpty()) {
			cout << " -> " << cages[safestPath.peek()]->getName();
			safestPath.pop();
		}
		cout << fixed << showpoint;
		cout << endl << "Probability: " << setprecision(6) << safestWeight << endl;
	}

	delete[] visited;
	delete[] indexLeft;
}

void ZooMap::findMostDangerousPath(const string startCage, const string endCage) {
	int cageCount = cages.getLength();
	bool* visited = new bool[cageCount];
	for (int i = 0; i < cageCount; i++){
		visited[i] = false;
	}

	int* indexLeft = new int[cageCount];
	for (int i = 0; i < cageCount; i++) {
		indexLeft[i] = 0;
	}

	int firstCage = cages.find(startCage);
	visited[firstCage] = true;
	MyStack<int> cageStack;
	MyStack<int> mostDangerousPath;
	double weightProduct = 1.0;
	double mostDangerousWeight = 1.0; // max value for live probability is 1

	cageStack.push(firstCage);
	weightProduct *= cages[firstCage]->getWeight();

	while (!cageStack.isEmpty()) {
		int cage = cageStack.peek();
		bool found = false;
		if (cages[cage]->getName() == endCage) {
			if (weightProduct < mostDangerousWeight) {
				mostDangerousWeight = weightProduct;
				mostDangerousPath = cageStack;
			}
			found = true;
		}
		while (indexLeft[cage] < cages[cage]->getAdjacentCages().getLength() &&
			visited[*cages[cage]->getAdjacentCages()[indexLeft[cage]]]) {
			indexLeft[cage]++;
		}
		if (indexLeft[cage] == cages[cage]->getAdjacentCages().getLength() // this means that all of the adjacent cages of the cage at the top of the stack is visited
			|| found) {
			visited[cage] = false;
			cageStack.pop();
			indexLeft[cage] = 0;
			weightProduct /= cages[cage]->getWeight();
		} else {
			int cageIndex = *cages[cage]->getAdjacentCages()[indexLeft[cage]];
			visited[cageIndex] = true;
			cageStack.push(cageIndex);
			indexLeft[cage]++;
			weightProduct *= cages[cageIndex]->getWeight();
		}
	}

	if (mostDangerousPath.getSize() == 0) {
		cout << "No path exists from " << startCage << " to " << endCage << "." << endl;
	} else {
		cout << "Most dangerous path from " << startCage << " to " << endCage << " is:" << endl;
		cout << startCage;
		mostDangerousPath.pop();
		while (!mostDangerousPath.isEmpty()) {
			cout << " -> " << cages[mostDangerousPath.peek()]->getName();
			mostDangerousPath.pop();
		}
		cout << fixed << showpoint;
		cout << endl << "Probability: " << setprecision(6) << mostDangerousWeight << endl;
	}

	delete[] visited;
	delete[] indexLeft;
}


