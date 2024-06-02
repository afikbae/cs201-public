/*
 * @author Mehmet Akif Sahin 22203673
 * @date 16 December 2023
 */
#ifndef ZOO_MAP_H_
#include <string>
#include "SortedLinkedList.h"
#include "Cage.h"
using namespace std;

class ZooMap {
public:
	ZooMap(const string cageFile, const string zooFile);
	~ZooMap();	
	void displayAllCages() const;
	void displayAdjacentCages(const string cageName) const;
	void displayZooMap() const;
	void findSafestPath(const string startCage, const string endCage);
	void findMostDangerousPath(const string startCage, const string endCage);
private:
	SortedLinkedList<Cage> cages;
};

#endif // !ZOO_MAP_H_
