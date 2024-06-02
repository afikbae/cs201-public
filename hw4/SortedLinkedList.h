/*
 * @author Mehmet Akif Sahin 22203673
 * @date 16 December 2023
 */
#ifndef SORTED_LINKED_LIST_H
#define SORTED_LINKED_LIST_H
#include <string>
template<class T>
class SortedLinkedList {
public:
	SortedLinkedList();
	~SortedLinkedList();
	bool isEmpty() const;
	int getLength() const;
	bool insert(T newEntry);
	void remove (int id);
	void clear ();
	bool contains (T& entry) const;
	int find (const std::string name) const;
	T* operator[] (int index) const;
private:
	typedef struct Node {
		T val;
		Node* next;
	} Node;
	Node* head;
	int size;
};
#include "SortedLinkedList.cpp"
#endif
