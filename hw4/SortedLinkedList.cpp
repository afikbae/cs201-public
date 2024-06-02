/*
 * @author Mehmet Akif Sahin 22203673
 * @date 16 December 2023
 */
#ifndef SORTED_LINKED_LIST_CPP
#define SORTED_LINKED_LIST_CPP
#include "SortedLinkedList.h"
#include <iostream>
#include <string>

template<class T>
SortedLinkedList<T>::SortedLinkedList () : head(nullptr), size(0) {}

template<class T>
SortedLinkedList<T>::~SortedLinkedList() {
	clear();
}

template<class T>
T* SortedLinkedList<T>::operator[](int i) const {
	if (i < 0 || i >= size) return nullptr;
	Node* temp = head;
	for (int j = 0; j < i; j++){
		if (temp == nullptr) std::cout << "invalid access " << i << std::endl;
		else temp = temp->next;
	}
	return &(temp->val);
}

template<class T>
bool SortedLinkedList<T>::isEmpty() const {
	return !size;
}

template<class T>
int SortedLinkedList<T>::getLength() const {
	return size;
}

template<class T>
bool SortedLinkedList<T>::insert(T entry) {
	if (contains(entry)) return false;
	size++;
	Node* insertAfter = head;
	if (insertAfter == nullptr || insertAfter->val > entry) {
		head = new Node;
		head->val = entry;
		head->next = insertAfter;
		return true;
	}
	for (; !(insertAfter->next == nullptr || entry < insertAfter->next->val); insertAfter = insertAfter->next);
	Node* newNode = new Node;
	newNode->next = insertAfter->next;
	newNode->val = entry;
	insertAfter->next = newNode;
	return true;
}

template<class T>
void SortedLinkedList<T>::remove(int id) {	
	Node* prev = nullptr, *cur = head;
	while (cur != nullptr) {
		if (cur->val == id) {
			Node* temp = cur;
			cur = cur->next;
			delete temp;
			size--;
		} else {
			if (prev == nullptr) {
				head = cur;
			} else {
				prev->next = cur;
			}
			prev = cur;
			cur = cur->next;
		}
	}
	if (prev == nullptr) {
		head = nullptr;
	} else {
		prev->next = nullptr;
	}
}

template<class T>
void SortedLinkedList<T>::clear() {
	while (head != nullptr) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

template<class T>
int SortedLinkedList<T>::find(const std::string name) const {
	if (size == 0) return -1;
	int k = 0;
	for (Node* temp = head; temp != nullptr; temp = temp->next) {
		if (temp->val == name) return k;
		k++;
	}
	return -1;
}

template<class T>
bool SortedLinkedList<T>::contains(T& entry) const {
	for (Node* node = head; node != nullptr; node = node->next) {
		if (node->val == entry) return true;
	}
	return false;
}
#endif
