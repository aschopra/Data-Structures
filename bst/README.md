Binary Search Tree of integers. Insert() and remove() operate in O(log N) time.
However, after a number of insertions and removals, this running time degenerates
to O(N) as the tree becomes more and more unbalanced. 

-Bug faced during implementation but RESOLVED:
	-In my insert(Node* temp, int data) helper function, 
	I previously prototyped it like this insert(Node* root, int data).
	I mistakingly thought that the local root variable inside of this
	function was the same as the private instance variable, root, of the
	class. Because of this, everytime I tried to print the BST, I was
	getting an empty tree since I was never actually building the BST
	from the class root variable. Instead, everytime insert() was called,
	it would get stuck in the if statement because it's local copy of root
	that was created every time the function was called was always null, meaning
	I was never actually creating links from the class' root member 
	variable that persists outside of the scope of this function. In short,
	I was saving the newly created node to the local root variable instead of
	the instance variable, root. Because the instance variable was always null, 
	I just kept setting the local root in insert() everyime the function
	was called. I fixed this issue by using a temporary Node ptr called 
	temp as the parameter to the recursive function, allowing me to set 
	the root instance variable the first time insert() was called.