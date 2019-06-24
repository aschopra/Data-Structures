class LinkedList {
private:
	struct Node {
		int val;
		Node* next;
	};

	Node* head; //keep track of start of list
public:
	//constructor
	LinkedList();

	//destructor 
	~LinkedList();

	void addNode(int val);

	void deleteNode(int val);

	void printList();
};