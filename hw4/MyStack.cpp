/*
 * @author Mehmet Akif Sahin 22203673
 * @date 16 December 2023
 */
#ifndef MY_STACK_CPP_
#define MY_STACK_CPP_
#include "MyStack.h"
#include <iostream>
#include <string>

template<typename T>
MyStack<T>::MyStack() : head(nullptr), size(0) {}

template<typename T>
MyStack<T>::~MyStack() {
	while (pop());
}

template<typename T>
void MyStack<T>::operator=(MyStack<T>& right) { // writes the content of the stack backwards to other stack
	while (pop());

	Node* node = right.head;
	while (node != nullptr) {
		push(node->item);
		node = node->next;
	}
}

template<typename T>
int MyStack<T>::getSize() {
	return size;
}

template<typename T>
bool MyStack<T>::isEmpty() {
	return head == nullptr;
}

template<typename T>
void MyStack<T>::push(T item) {
	size++;
	if (head == nullptr) {
		head = new Node;
		head->item = item;
		head->next = nullptr;
	} else {
		Node* newNode = new Node;
		newNode->next = head;
		newNode->item = item;
		head = newNode;
	}
}

template<typename T>
bool MyStack<T>::pop() {
	if (head == nullptr) return false;
	Node* temp = head->next;
	delete head;
	head = temp;
	size--;
	return true;
}

template<typename T>
T MyStack<T>::peek() {
	return head->item;
}

#endif // !MY_STACK_CPP_
