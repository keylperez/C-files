#include<stdio.h>

void BubbleSort(int A[], int n);

int main(){
	int a[] = {3,44,38,5,47,15,36,26,27,2,46,4,19,50,48};
	int size = 15, i;
	BubbleSort(a, size);
	for (i = 0; i < size; i++){
    	printf("%d\n", a[i]);
    }
	return 0;
}

void BubbleSort(int A[], int n){
	int i, x, temp;
	for(i=0;i < n - 1;i++){
		
		for(x = 0; x < n - i -1; x++){
			if(A[x] > A[x+1]){
				temp = A[x];
				A[x] = A[x+1];
				A[x+1] = temp;
			}
		}
	}
}
