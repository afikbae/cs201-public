/*
 * @author Mehmet Akif Sahin 22203673
 * @date 16 December 2023
 */
#ifndef MY_STACK_H_
#define MY_STACK_H_
#include <string>
template<typename T>
class MyStack {
public:
	MyStack();
	~MyStack();
	void operator=(MyStack<T>& right);
	bool isEmpty();
	void push(T);
	bool pop();
	T peek();
	int getSize();
private:
	typedef struct Node {
		T item;
		Node* next;
	} Node;
	Node* head;
	int size;
};
#include "MyStack.cpp" 
#endif // !MY_STACK_H_
