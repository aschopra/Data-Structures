#include "queue.h"
#include <iostream>

Queue::Queue() {
	front = NULL;
	rear = NULL;
}

Queue::~Queue() {
	while(front != NULL) {
		node* temp = front;
		front = front->next;
		delete temp;
	}
}

void Queue::enqueue(int item) {
	node* newNode = new node(item);
	newNode->next = NULL;
	if(rear != NULL) {
		rear->next = newNode;
	}
	rear = newNode;
	// handles case of adding first item to queue
	if(front == NULL) {
		front = rear;
	}
}

int Queue::dequeue() {
	if(isEmpty()) {
		std::cout << "Error: cannot dequeue from empty queue" << std::endl;
		return -1;
	}
	node* oldFront = front; 
	int data = front->data; // save old head's value
	front = front->next; // advance head
	if(front == NULL) {
		rear = NULL;
	}
	oldFront->next = NULL;
	delete oldFront;
	return data;
}

int Queue::peek() {
	if(isEmpty()) {
		std::cout << "Error: cannot retrieve top item from empty queue" << std::endl;
		return -1;
	}
	return front->data;
}

bool Queue::isEmpty() {
	return front == NULL && rear == NULL;
}

void Queue::printQueue() {
	node* temp = front;
	while(temp != NULL) {
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}