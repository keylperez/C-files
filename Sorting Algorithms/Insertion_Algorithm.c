#include<stdio.h>

void InsertionSort(int A[], int n);

int main(){
	int a[] = {3,44,38,5,47,15,36,26,27,2,46,4,19,50,48};
	int size = 15, i;
	InsertionSort(a, size);
	for (i = 0; i < size; i++){
    	printf("%d\n", a[i]);
    }
	return 0;
}

void InsertionSort(int A[], int n){
	int i = 0, j = 0;
	int x, y, z, temp;
	//i for already sorted
	//x for unsorted
	//z for current unsorted
	//y for current element
	for(x = 1; x < n ; x++, i++){//right-most sorted
		
		for(y = i, z = x, j = 0; !j ; y--, z--){//swapping loop
			
			j = 1;
			if(A[z] < A[y]){//swapping condition
				
				temp =  A[y];
				A[y] = A[z];
				A[z] = temp;
				j = 0;
			}
		}
	}
}

