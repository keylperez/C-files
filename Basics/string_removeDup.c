#include <stdio.h>
#include <string.h>

char removeDup(char string[]);

int main(){
	char string[] = "ABBBCDDEF";
	
	puts("Before removing dups: ");
	puts(string);
	
	removeDup(string);
	
	puts("After removing dups: ");
	puts(string);
	
	return 0;
}

char removeDup(char string[]){
	int n = strlen(string);
	int i, x, y;
	for (i = 0; i < n; i++){
		for(x = (i+1);x < n; x++){
			if(string[i] == string[x]){
				for(y = x; y < n; y++){
						string[y] = string[y+1];
				}
				n--;
				x = i;
			}
		}
	}
}
