#include <stdio.h>
#include <stdlib.h>

int* findEven(int arr[], int size);

int main(){
	int size = 5;
	int arr[] = {1, 2, 3, 4, 5};
	int *ptr;
	ptr = findEven(arr, size);
	free(ptr);
	return 0;
}

int* findEven(int arr[], int size){
	int *arr2, i=0, n=0, x=0;
	while (i<size){
		if (arr[i]%2 == 0){
			n++;
		}
		i++;
	}
	arr2 = (int*) calloc(n+1, sizeof(int));
	i = 0;
	while(i < size){
		if (arr[i]%2 == 0){
			arr2[x] = arr[i];
			x++;
		}
		i++;
	}
	arr2[n]= -1;
	return arr2;
}
