#ifndef SORTED_LINKED_LIST_H
#define SORTED_LINKED_LIST_H
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
	T* find (int id) const;
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
