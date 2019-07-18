class Stack {
private:
	struct Node {
		int data;
		Node* next;

		Node(int data) {
			this->data = data;
		}
	};
	Node* top; // denotes the top of stack
public:
	Stack(); // constructor
	~Stack(); // destructor
	void push(int item); // add item to top of stack
	int pop(); // remove and return top element of stack
	int peek(); // return top element of stack
	bool isEmpty(); // returns whether stack empty or not
	void printStack(); // helper function for testing
};