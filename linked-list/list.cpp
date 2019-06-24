#include "list.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList() {
	head = NULL;
}

LinkedList::~LinkedList() {
	while(head != NULL) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

//add to end of linked list--O(n) insertion
void LinkedList::addNode(int val) {
	Node* n = new Node();
	n->val = val;
	n->next = NULL;

	if(head == NULL) {
		head = n;
	} else {
		Node* curr = head;
		while(curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = n;
	}
}

void LinkedList::deleteNode(int val) {
	//Case 1: deleting head of linked list
	if(head->val == val) {
		Node* oldHead = head;
		head = head->next;
		delete oldHead;
		cout << "The value " << val << " has been deleted" << endl;
		return;
	} else {
		//Case 2: deleting node in middle/end of list
		Node* curr = head;
		while(curr->next != NULL) {
			if(curr->next->val == val) {
				Node * temp = curr->next;
				curr->next = temp->next;
				temp->next = NULL;
				delete temp;
				cout << "The value " << val << " has been deleted" << endl;
				return;
			}
			curr = curr->next;
		}

		cout << val << " was not found" << endl;
	}
}

void LinkedList::printList() {
	Node* curr = head;
	while(curr != NULL) {
		cout << curr->val << " ";
		curr = curr->next;
	}
	cout << endl;
}