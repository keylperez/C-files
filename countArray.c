#include <stdio.h>

int createCountArray(int array[], int size);

int main(){
	int arr[] = {12, 1, 2, 4, 2, 3, 10, 8, 11};
	int size = sizeof(arr)/4;
	int i; 
	int *newArr;
	printf("unsorted:\t");
	for ( i = 0; i < size; i++ ){
		printf("%d\t", arr[i]);
	}
	printf("\nindex:\t\t");
	for ( i = 0; i < size; i++ ){
		printf("%d\t", i);
	}
	newArr = createCountArray(arr, size);
	printf("\nSorted:\t\t");
	for ( i = 0; i < size; i++ ) {
      printf( "%d\t", i, *(newArr + i));
   }
	printf("\nindex:\t\t");
	for ( i = 0; i < size; i++ ){
		printf("%d\t", i);
	}
}

int createCountArray(int array[], int size){
	int i, x, y, z, temp;
  	for(i = 0;i < size - 1; i++){
    	if(array[i] > array[i+1]){
	    	z = array[i];
	    }
	  }
	
	  int countArray[z + 1];
	  for(i = 0; i < size; i++){
	    for(x = i+1; x < size; x++){
	      if (array[x] < array[i]){
	        y = x;
	      }
	    }
	    temp = array[i];
	    array[i] = array[y];
	    array[y] = temp;
	  }
	  temp = 0;
	  for(i = 0;i < z; i++){
	    for(x = 1; x < z; x++){
	      if(array[i] == array[x]){
	        temp++;
	        for(y = 0; y < z; y++){
	        countArray[y] = temp;
	        }
	      }
	    }
	  }
	countArray[z] = -1;
	return countArray;
}
