#ifndef CONTENT_CREATOR_H
#define CONTENT_CREATOR_H
#include <string>
#include "SortedLinkedList.h"
#include "User.h"
#include "Content.h"
class ContentCreator {
public:
	ContentCreator(int=0, std::string="");
	bool operator< (ContentCreator&)const;
	bool operator> (ContentCreator&)const;
	bool operator== (ContentCreator&)const;
	bool operator== (int)const;
	SortedLinkedList<int>& getFollowers();
	SortedLinkedList<Content>& getContents();
	int getId()const;
	std::string getName()const;
	Content addContent(int, std::string);
	bool removeContent(int);
	bool follow(int);
	bool unfollow(int);
	void showContents() const;
	void showFollowers() const;
	std::string toString() const;
private:
	int id;
	std::string name;
	SortedLinkedList<int> followers;
	SortedLinkedList<Content> contents;
};
#endif // !CONTENT_CREATOR_H
