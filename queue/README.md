Queue implemented with a linked list. All operations run in O(1) time.

Bug: When trying to test peek() on an empty queue, I was getting a 
segmentation fault (core dumped) error because in the if statement in 
peek() that checked whether the queue was empty, I was merely printing
out that there was an error and forgot to immediately return -1. Because
of this, I would print the error message, then attempt to return front->data,
which would seg fault because I was trying to access the data variable of NULL.
I fixed this careless error by immediately returning -1 in the if statement when
the queue is empty.