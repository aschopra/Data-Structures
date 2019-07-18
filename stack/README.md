Stack implementation using a linked list. All functions operate in O(1) time. 

-Logic Error:
	-In printStack(), I thought I encountered a bug with my push function 
	because I was seeing the first element I added appear twice. However,
	this was just because when testing functionality, I was calling
	printStack() after every push() call rather than calling push() 
	a few times, then printStack() only once to see the most up to
	date version of the stack. On top of this, I was not printing
	out a new line after each element of the stack was seen, but rather
	just a space. This means when I would call push(2), printStack(),
	push(4), printStack(), I was seeing '2 4 2' in the output. However,
	this output is correct because the first '2' is from the printStack() call
	after the first push call and the '4 2' is from the second push call's 
	printStack(). Calling printStack() after each push() call is not problematic, 
	but can be confusing when testing and ensuring the output is correct.