#include "BST.h"
#include <iostream>
#include <climits>

BST::BST() {
	root = NULL;
}

BST::~BST() {
	deleteTree(root);
}

void BST::deleteTree(Node* temp) {
	// post-order traversal to delete: Left, Right, Root
	if (temp == NULL) {
		return;
	}
	deleteTree(temp->left);
	deleteTree(temp->right);
	delete temp;
}

BST::Node* BST::createNode(int data) {
	Node* newNode = new Node(data);
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void BST::insert(int data) {
	insert(root, data);
}

// private helper function to insert node
void BST::insert(Node* temp, int data) {
	// check for empty tree to set root
	if (root == NULL) {
		root = createNode(data);
	} else if (data < temp->data) {
		if (temp->left != NULL) {
			// recurse down left sub-tree
			insert(temp->left, data);
		} else {
			temp->left = createNode(data);
		}
	} else if (data > temp->data) {
		// recurse down right sub-tree
		if (temp->right != NULL) {
			insert(temp->right, data);
		} else {
			temp->right = createNode(data);
		}
	} else {
		// duplicate entries not permitted
		std::cout << data << " has already been added to the BST" << std::endl;
	}
}

void BST::printInOrder() {
	printInOrder(root);
	std::cout << std::endl;
}

// private helper func for in-order traversal
void BST::printInOrder(Node* temp) {
	if (temp == NULL) {
		return;
	}
	printInOrder(temp->left);
	std::cout << temp->data << " ";
	printInOrder(temp->right);
}

// return ptr to node with given data val
BST::Node* BST::findNode(int data) {
	return findNode(root, data);
}

BST::Node* BST::findNode(Node* temp, int data) {
	if (temp == NULL) {
		return NULL;
	} else if (data == temp->data) {
		return temp;
	} else if (data < temp-> data) {
		return findNode(temp->left, data);
	} else {
		return findNode(temp->right, data);
	}
}

// print children of given node
void BST::printChildren(int data) {
	Node* temp = findNode(data);
	if (temp != NULL) {
		std::cout << "Parent Node: " << temp->data << std::endl;
		// check for left child
		temp->left != NULL ? 
		std::cout << "Left Child: " << temp->left->data << std::endl :
		std::cout << "Left Child is NULL" << std::endl;
		// check for right child
		temp->right != NULL ? 
		std::cout << "Right Child: " << temp->right->data << std::endl :
		std::cout << "Right Child is NULL" << std::endl;
	}
}

int BST::getMin() {
	return getMin(root);
}

int BST::getMin(Node* temp) {
	if (root == NULL) {
		std::cout << "Error: The tree is empty" << std::endl;
		return INT_MIN;
	}
	if (temp->left == NULL) {
		return temp->data;
	}
	return getMin(temp->left);
}

void BST::remove(int data) {
	root = remove(root, data);
}

BST::Node* BST::remove(Node* root, int data) {
	// locate the node to remove
	if (root == NULL) {
		std::cout << "Unable to locate " << data << std::endl;
		return NULL;
	} else if (data < root->data) {
		// search the left subtree
		root->left = remove(root->left, data);
	} else if (data > root->data) {
		// search right subtree
		root->right = remove(root->right, data);
	} else {
		// 0 children
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		} else if (root->left == NULL) {
			// has 1 child on right
			Node* temp = root;
			root = root->right;
			delete temp;
		} else if (root->right == NULL) {
			// has 1 child on left
			Node* temp = root;
			root = root->left;
			delete temp;
		} else {
			// 2 children
			Node* temp = root;
			// locate successor
			temp = temp->right;
			while (temp->left != NULL) {
				temp = temp->left;
			}
			root->data = temp->data; // swap data values
			root->right = remove(root->right, temp->data); // delete duplicate
		}
	}
	return root;
}

