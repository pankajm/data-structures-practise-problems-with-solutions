
/***    Author : Pankaj Marghade 
	Date   : 7 sep, 2015    
	license: GNU general public license v3.0 ***/

#define size 100
typedef struct node{
	int key;
	int value;
}node;

typedef struct counter{	 // to keep track of last index in an array
	int index;
	node *arr[size];
}counter;

void initCounter(counter *);
void insertInHeap(counter *, int, int);
node *deleteFromHeap(counter *);
void percolateUp(counter *);
void percolateDown(counter *);
void displayHeap(counter *);
