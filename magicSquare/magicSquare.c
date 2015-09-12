#include<stdio.h>
#include<stdlib.h>
int size;
int createMagicSquare(long arr[][size]){

	long lastNumber = size * size, i, j, flag;
	int xCoOrdinate = 0, yCoOrdinate;
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++)
		{
			arr[i][j] = 0;
		}
	}
	for(i = 1; i <= lastNumber; i++){
	
		if(i == 1){
			yCoOrdinate = 0;
			xCoOrdinate = size/2;
			arr[xCoOrdinate][yCoOrdinate] = i;
		}
		else{
			if(yCoOrdinate - 1 < 0 && xCoOrdinate + 1 == size)
			{
				yCoOrdinate++;
				arr[xCoOrdinate][yCoOrdinate] = i;
			}
			else
			{
				flag = 0;
				if(yCoOrdinate - 1 < 0)
				{
					xCoOrdinate = xCoOrdinate + 1;
					yCoOrdinate = size - 1;
					flag = 1;
				}
				else if(xCoOrdinate + 1 == size)
				{
					xCoOrdinate = 0;
					yCoOrdinate = yCoOrdinate - 1;
					flag = 1;
				}
				if(!flag){
					xCoOrdinate = xCoOrdinate + 1;
					yCoOrdinate = yCoOrdinate - 1;
				}
				if(arr[xCoOrdinate][yCoOrdinate] != 0)
				{
					if(flag)
						yCoOrdinate++;
					else{
						xCoOrdinate--;
						yCoOrdinate+=2;
					}
				}
				arr[xCoOrdinate][yCoOrdinate] = i;
			}
		}
	}
}

int main(){

	printf("Enter dimension\n");
	scanf("%d", &size);
	long i, j;
	long magic[size][size];
	createMagicSquare(magic);
	for(j = 0; j < size; j++){
		for(i = 0; i < size; i++)
			printf("%li ", magic[i][j]);
		printf("\n");
	}
	return 0;
}

