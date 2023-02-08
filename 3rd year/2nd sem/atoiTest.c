
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{

    char string[20];

    scanf("%s", string);

    int val;

    // for(i = 0; string[i] != '\0' || string[i] ; i+=){}
    val = atoi(string + 1);

    printf("\n%d", val);
    printf("\n%s", string);

    return 0;
}