#include "priorityQueue.h"
#include<stdio.h>
#include<stdlib.h>
int main(){

	int choice, key, value;
	node *heapNode;
	counter c;
	initCounter(&c);
	while(1){
	
		printf("----JOB SCHEDULER----\n\nEnter choice\n1. Read Job\n2. Feed Job\n3. Display Heap\n");
		scanf("%d", &choice);
		switch(choice){
	
			case 1:
				heapNode = deleteFromHeap(&c);
				if(heapNode == NULL)
					printf("Heap is empty\n");
				else
					printf("Job with highest priority is %d - %d\n", heapNode -> key, heapNode -> value);
				break;
			case 2:
				printf("Enter the key and value\n");
				scanf("%d %d", &key, &value);
				insertInHeap(&c, key, value);
				displayHeap(&c);
				printf("\n");
				break;
			case 3:
				displayHeap(&c);
				printf("\n");
				break;
			dafault:
				exit(0);
	
		}
	
	}
}
