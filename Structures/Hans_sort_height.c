#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RECORDS 10

typedef struct child {
    char *name;
    unsigned int height;
} child;

child createChildRecord();
child *sort_height(child *records);

int main() {
    int i;
    child childRecords[RECORDS];
    child *sortedRecords;

    for(i = 0; i < RECORDS; i++) {
        printf("Record %d\n", i + 1);
        childRecords[i] = createChildRecord();
    }

    sortedRecords = sort_height(childRecords);

    for (i = 0; i < RECORDS; i++) {
        printf("%-2d %-11s %dcm\n", i + 1, (sortedRecords + i)->name, (sortedRecords + i)->height);
        free(childRecords[i].name);
    }
    
    free(sortedRecords);

    return 0;
}

child createChildRecord() {
    char temp[10];
    child thisChild;
    
    printf("Enter name: ");
    scanf("%s", &temp);             /* ensure no buffer overflow pls */
    printf("Enter height (in cm): ");
    scanf("%d", &thisChild.height);
    printf("\n");

    /* dump string to malloc-ed member  */
    thisChild.name = malloc(sizeof(char) * (strlen(temp) + 1));
    strcpy(thisChild.name, temp);

    return thisChild;
}

child *sort_height(child *records) {
    int i, j;
    child temp;
    child *sorted = malloc(sizeof(child) * RECORDS);
    
    for(i = 0; i < RECORDS; i++) {
        for(j = i + 1; j < RECORDS; j++) {     
            if((records + i)->height > (records + j)->height) {
                temp = records[j];
                records[j] = records[i];
                records[i] = temp;
            }
        }
        sorted[i] = records[i];
    }

    return sorted;
}