#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int *sortingSouls(int arr[], int size);
//void sortingSouls(int arr[], int size);

void displaySouls(int arr[], int size);

int main(){
	int soulScores[] = {11,11,48,12,38,4,12,33,12,38,11};
	int soulSize = (sizeof(soulScores)/sizeof(int));
	int *MediocrisSouls, i;
	
	printf("Scores of Souls:\n");
	displaySouls(soulScores, soulSize);
	MediocrisSouls = sortingSouls(soulScores, soulSize);
//	printf("\nreturn size: %d\n", sizeof(MediocrisSouls)/2);

//	printf("{");
//	for(i = 0; i < sizeof(MediocrisSouls)/2; i++){
//		printf("%d ", *MediocrisSouls++);
//	}
//	printf("}\n");
	
//	sortingSouls(soulScores, soulSize);
	free(MediocrisSouls);
	
	return 0;
}
//void sortingSouls(int arr[], int size){
int *sortingSouls(int arr[], int size){
	int i, x, I1, I2, I2best;
	
	//gets greates value
	for(i = 0, I1 = 0; i < size; i++){
		
		if(arr[i] > I1) {
			
			I1 = arr[i];
		}
//		printf("%d\n", I1);
	}
	
//	printf("%d\n", I1);
	
	for(i = 0, I2 = 0; i < size; i++){
		//I1 is 8
		if(arr[i] > I2 && arr[i] < I1){
			
			I2 = arr[i];
			I2best = i;
			
		}
//		printf("%d\n", I2);
	}
//	printf("index of 2nd best: %d\n", I2best);
	
	int *secondBest = (int *)malloc(size - I2best);
	memcpy(secondBest, arr + I2best, (size - I2best)*sizeof(int));
	
	printf("\nScore of the souls of Mediocris:\n");
	displaySouls(secondBest, size - I2best);
//	printf("sizeof secondBest: %d", size - I2best);
	
	return secondBest;
}


void displaySouls(int arr[], int size){
	int i;
	
	printf("{");
	
	for(i = 0; i < size; i++){
		
		printf("%d ", arr[i]);
	}
	
	printf("}\n");
}
