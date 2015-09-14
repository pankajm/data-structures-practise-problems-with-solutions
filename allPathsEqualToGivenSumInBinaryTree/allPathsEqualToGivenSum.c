	/* its only the c function which prints all paths from root to any node in a binary tree that sums up to given sum. 
           The code is designed to work for negative numbers as well.
 	   Time Complextiy := o(n)  */

	/* for this function to work, put this in any binary tree implementation code and pass the initial parameters as follows

	root = root of tree;
	index = 0
	sum = 0
	givenSum = givenSum in problem */

void findPaths{tree *root, int arr[], int index, int sum, int givenSum{

	if(root == NULL)
		return;
	arr[index] = root -> data;
	sum = sum + root -> data;
	if(sum == givenSum){
	
		for(int i = 0; i <= index; i++){
		
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
	findPaths(root -> left, arr, index + 1, sum, givenSum);
	findPaths(root -> right, arr, index + 1, sum, givenSum);
}
