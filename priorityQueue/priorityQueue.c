#include<stdio.h>
#include<stdlib.h>
#include "priorityQueue.h"

void initCounter(counter *current){

	current -> index = -1;
}

void insertInHeap(counter *current, int key, int value){
	
	node *temp = (node *)malloc(sizeof(node));
	temp -> key = key;
	temp -> value = value;
	current -> index = current -> index + 1;
	current -> arr[current -> index] = temp;
	percolateUp(current);

}

node *deleteFromHeap(counter *current){
	
	if(current -> index == -1)
		return NULL;
	node *temp = current -> arr[0];
	current -> arr[0] = current -> arr[current -> index];
	current -> index = current -> index - 1;
	percolateDown(current);
	return temp;
}

void percolateUp(counter *current){

	int currentIndex = current -> index;
	node *temp;
	while(currentIndex != 0){
		
		if((current -> arr[currentIndex] -> value) > (current  -> arr[(currentIndex - 1)/2] -> value))
		{
			
			node *temp = current -> arr[currentIndex];
		 	current -> arr[currentIndex] = current -> arr[(currentIndex - 1)/2];
			current -> arr[(currentIndex - 1)/2] = temp;
			currentIndex = (currentIndex - 1)/2;
		}
		else 
			break;

	}

}

void percolateDown(counter *current){

	int index = 0;
	node* temp;
	while((2*index + 2) <= current -> index){

		if(current -> arr[index] -> value < current -> arr[2 * index + 1] -> value || current -> arr[index] -> value < current -> arr[2 * index + 2] -> value)
		{
			if(current -> arr[2 * index + 1] -> value > current -> arr[2 * index + 2] -> value){
				temp = current -> arr[2 * index + 1];
				current -> arr[2 * index + 1] = current -> arr[index];
				current -> arr[index] = temp;
				index = 2*index + 1;	
			}
			else{
				temp = current -> arr[2 * index + 2];
				current -> arr[2 * index + 2] = current -> arr[index];
				current -> arr[index] = temp;
				index = 2*index + 2;	
			}
			
		}
		else
			break;	
	}
	if((2*index + 1) <= current -> index){
	
		if(current -> arr[2 * index + 1] -> value > current -> arr[index] -> value)
		{
				temp = current -> arr[2 * index + 1];
				current -> arr[2 * index + 1] = current -> arr[index];
				current -> arr[index] = temp;
				index = 2*index + 1;
		}
	
	}

}

void displayHeap(counter *current){

	int i = 0;
	while(i <= current -> index){
		printf("%d - %d\t", current -> arr[i] -> key, current -> arr[i] -> value); 
		i++;
	}
}

