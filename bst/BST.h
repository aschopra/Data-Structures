class BST {
private:
	struct Node {
		int data;
		Node* left;
		Node* right;

		Node(int data) {
			this->data = data;
		}
	};
	Node* root;
	Node* createNode(int data);
	void insert(Node* temp, int data);
	void printInOrder(Node* temp);
	Node* findNode(int data);
	Node* findNode(Node* temp, int data);
	int getMin(Node* temp);
	Node* remove(Node* temp, int data);
	void deleteTree(Node* temp);
public:
	BST();
	~BST();
	void insert(int data);
	void printInOrder(); // in-order traversal
	void printChildren(int data);
	int getMin();
	void remove(int data);

};