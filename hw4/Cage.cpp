/*
 * @author Mehmet Akif Sahin 22203673
 * @date 16 December 2023
 */
#include "Cage.h"
#include <string>
#include "SortedLinkedList.h"

Cage::Cage(std::string name, double weight) : name(name), weight(weight) {}

bool Cage::operator== (Cage& right) {
	return name == right.name;
}

bool Cage::operator<(Cage& right) {
	return name < right.name;
}

bool Cage::operator>(Cage& right) {
	return name > right.name;
}

bool Cage::operator==(const std::string& right) {
	return name == right;
}

std::string Cage::getName() const {
	return name;
}

double Cage::getWeight() const {
	return weight;
}

SortedLinkedList<int>& Cage::getAdjacentCages() {
	return adjacentCages;
}
