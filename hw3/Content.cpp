#include "Content.h"
#include <string>

Content::Content(int id, std::string title) : id(id), title(title) {}

bool Content::operator< (Content& right) const {
	return id < right.id;
}

bool Content::operator> (Content& right) const {
	return right.id < id;
}

bool Content::operator== (Content& rigth) const {
	return id == rigth.id;
}

bool Content::operator== (int i) const {
	return id == i;
}

int Content::getId() const {
	return id;
}
