
/***    Author : Pankaj Marghade 
	Date   : 6 sep, 2015    
	license: GNU general public license v3.0 ***/

/* Please find license copy at - http://www.gnu.org/licenses/gpl-3.0.en.html */

/* Problem stmt :- An operation "swap" means removing an element from the array and appending it at the back of the same array. Find the minimum number of "swaps" needed to sort that array

Eg :- 3124
Output: 2 (3124->1243->1234)
expected Complexity :- O(n) */


// Algo - 
/* We will swap the number if its greater than its next number and 
   maintain the minimum number swaped in this process.
   if the number is not greater then we check if its greater than the last minimum number swaped, 
   if greater then increase the count by 1 as we need to replace this number as well in future. */

#include<stdio.h>
int countSwaps(int arr[], int no){

	int i, count = 0, lastMin = -1;
	for(i = 0; i < no; i++)
	{
		if(i != no - 1 && arr[i] > arr[i+1]){
			count = count + swap();
			if(lastMin == -1)
				lastMin = arr[i];
			if(arr[i] < lastMin)
				lastMin = arr[i];
		}
		else if(lastMin != -1 && arr[i] > lastMin)
			count = count + swap();
	
	}
	return count;
}

int swap(){
	return 1;
}

int main(){

	int arr[] = {1, 7, 3, 2, 4, 5, 6};
	int totalSwapsReq = countSwaps(arr, 7);
	printf("Total swaps required to sort the array is %d\n", totalSwapsReq);
	return 0;
}
