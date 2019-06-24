#include "list.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	LinkedList* list = new LinkedList();
	list->addNode(3);
	list->addNode(5);
	list->addNode(7);
	list->printList();
	list->deleteNode(7);
	list->printList();
	delete list;
	return 0;
}