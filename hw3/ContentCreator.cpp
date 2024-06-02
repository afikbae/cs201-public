#include "ContentCreator.h"
#include "Content.h"
#include "SortedLinkedList.h"
#include <string>
#include <iostream>

ContentCreator::ContentCreator(int id, std::string name) : id(id), name(name) {};

bool ContentCreator::operator< (ContentCreator& right) const {
	return id < right.id;
}

bool ContentCreator::operator> (ContentCreator& right) const {
	return id > right.id;
}

bool ContentCreator::operator== (ContentCreator& right) const {
	return id == right.id;
}

bool ContentCreator::operator== (int i) const {
	return id == i;
}

SortedLinkedList<int>& ContentCreator::getFollowers() {
	return followers;
}

SortedLinkedList<Content>& ContentCreator::getContents() {
	return contents;
}

int ContentCreator::getId() const {
	return id;
}

std::string ContentCreator::getName() const {
	return name;
}

Content ContentCreator::addContent(int contentId, std::string title) {
	Content newContent(contentId, title);
	contents.insert(newContent);
	return newContent;
}

bool ContentCreator::removeContent(int id) {
	Content* content = contents.find(id);
	if (content) {
		contents.remove(id);
		return true;
	} else return false;
}

bool ContentCreator::follow(int userId) {
	int* id = followers.find(userId);
	if (id) {
		return false;
	}
	followers.insert(userId);
	return true;
}

bool ContentCreator::unfollow(int userId) {
	int* id = followers.find(userId);
	if (!id) {
		return false;
	}
	followers.remove(userId);
	return true;
}

void ContentCreator::showContents() const {
	std::cout << "Contents of content creator with ID " << id << ":" << std::endl;
	if (contents.getLength() == 0) std::cout << "None" << std::endl;
	for (int i = 0; i < contents.getLength(); i++) {
		std::cout << contents[i]->getId() << std::endl;
	}
}

void ContentCreator::showFollowers() const {
	std::cout << "Regular users following content creator with ID " << id << ":" << std::endl;
	if (followers.getLength() == 0) std::cout << "None" << std::endl;
	for (int i = 0; i < followers.getLength(); i++) {
		std::cout << *followers[i] << std::endl;
	}
}

std::string ContentCreator::toString() const {
	return std::to_string(id) + ", " + name + ", " + std::to_string(followers.getLength()) + " follower(s), " + std::to_string(contents.getLength()) + " content(s)";
}
