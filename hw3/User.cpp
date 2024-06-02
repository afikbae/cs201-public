#include "User.h"
#include <string>

User::User(int id, std::string name) : id(id), name(name){};

bool User::operator< (User& right) const{
	return id < right.id;
}

bool User::operator> (User& right) const{
	return id > right.id;
}

bool User::operator== (User& right) const{
	return id == right.id;
}

bool User::operator== (int i) const{
	return id == i;
}

int User::getId()  const{
	return id;
}

std::string User::toString() const {
	return std::to_string(id) + ", " + name;
}
