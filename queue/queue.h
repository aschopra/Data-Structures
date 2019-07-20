class Queue {
	private:
		struct node {
			int data;
			node* next;

			node(int data) {
				this->data = data;
			}
		};
		node* front; // dequeue from front
		node* rear; // enqueue from rear
	public:
		Queue();
		~Queue();
		void enqueue(int item);
		int dequeue();
		int peek();
		bool isEmpty();
		void printQueue();
};