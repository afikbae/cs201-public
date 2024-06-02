/*
 * @author Mehmet Akif Sahin 22203673
 * @date 16 December 2023
 */
#ifndef CAGE_H_
#define CAGE_H_
#include "SortedLinkedList.h"
#include <string>

class Cage {
public:
	Cage(std::string = "", double = 0.0);
	bool operator==(Cage& right);
	bool operator<(Cage& right);
	bool operator>(Cage& right);
	bool operator==(const std::string& right);
	std::string getName() const;
	double getWeight() const;
	SortedLinkedList<int>& getAdjacentCages();
private:
	std::string name;
	double weight;
	SortedLinkedList<int> adjacentCages;
};

#endif // !CAGE_H_
