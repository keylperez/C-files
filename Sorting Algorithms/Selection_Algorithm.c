#include<stdio.h>

void SelectionSort(int A[], int n);

int main(){
	int a[] = {3,44,38,5,47,15,36,26,27,2,46,4,19,50,48};
	int size = 15, i;
	SelectionSort(a, size);
	for (i = 0; i < size; i++){
    	printf("%d\n", a[i]);
    }
	return 0;
}

void SelectionSort(int A[], int n){
	int i, x, y,temp;
	
	for(y = 0; y < n; y++){
		i = y;
		
		for(x = i+1;x < n;x++){
			
			if (A[i] > A[x]){
				i = x;
			}	
		}
		temp =  A[y];
		A[y] = A[i];
		A[i] = temp;
	}
}

//void SelectionSort(int A[], int n){
//	int i, x, y,temp;
//	
//	for(y = 0; y < (n - 1); y++){
//		i = y;
//		
//		for(x = i+1;x < n;x++){
//			
//			if (A[i] > A[x]){
//				i = x;
//			}	
//		}
//		if(i != y){
//			temp =  A[y];
//			A[y] = A[i];
//			A[i] = temp;
//		}
//	}
//}

