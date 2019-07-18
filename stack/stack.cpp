#include "stack.h"
#include <iostream>

// constructor
Stack::Stack() {
	top = NULL;
}

// destructor
Stack::~Stack() {
	while(!isEmpty()) {
		Node* temp = top;
		top = top->next;
		delete temp;
	}
}

// add item to top of stack
void Stack::push(int item) {
	Node* newNode = new Node(item);
	newNode->next = top;
	top = newNode;
}

// remove and return top element of stack
int Stack::pop() {
	// check whether stack is empty
	if (top == NULL) {
		std::cout << "Error: Cannot pop from empty stack" << std::endl;
		return -1;
	}
	Node* temp = top;
	int data = temp->data;
	top = top->next;
	delete temp;
	return data;
}

// return top element of stack
int Stack::peek() {
	if(top == NULL) {
		std::cout << "Error: Cannot get top element from empty stack" << std::endl;
		return -1;
	}
	return top->data;
}

// returns whether stack empty or not
bool Stack::isEmpty() {
	return top == NULL;
} 

void Stack::printStack() {
	Node* temp = top;
	while(temp != NULL) {
		std::cout << temp->data << " ";
		temp = temp->next;
	}
}