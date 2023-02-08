#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 30
typedef struct
{
	char data[300];
	int group;
	int link;
} Nodetype;
typedef struct VHnode
{
	Nodetype heap[SIZE];
	int availList;
} * VHeap; // Shared by all cursorList
typedef struct
{
	int elemPtr; // Points to the first element of the list
	VHeap VH;	 // Points to the shared Virtual Heap
} cursorList;	 //  Definition of the cursor list

void initVirtualHeap(VHeap *VH);
void displayVirtualHeap(VHeap VH);
void initCursorList(cursorList *L, VHeap VH);
void insert(cursorList *L, int group, char str[]);
void populateList(cursorList *L);
void displayList(cursorList L);

// Main problem
cursorList getGroup(cursorList *L, int group);

void main()
{

	cursorList A, Story1, Story2; // create Lists
	VHeap V;					  // Template Virtual Heap

	printf("\n\n\nTask 1: \n");
	initVirtualHeap(&V);
	displayVirtualHeap(V);

	printf("\n\n\nTask 2: ");
	initCursorList(&A, V);
	displayList(A);

	printf("\n\n\nTask 3: ");
	populateList(&A);
	displayList(A);

	Story1 = getGroup(&A, 1);
	Story2 = getGroup(&A, 2);
	printf("\n\n\nTask 4 (Story 1): ");
	displayList(Story1);
	printf("\n\n\nTask 4 (Story 2): ");
	displayList(Story2);
	printf("\n\n\nTask 4 (Original List): ");
	displayList(A);
	printf("\n\n\nVirtual heap:");
	displayVirtualHeap(V);
}

void initVirtualHeap(VHeap *VH)
{
	*VH = (VHeap)calloc(1, sizeof(struct VHnode)); // allocate space
	(*VH)->availList = 0;						   // available index is at 0
	int ndx;

	(*VH)->heap[SIZE - 1].link = -1;	  // last index points to -1 which signifies end of list
	for (ndx = SIZE - 2; ndx >= 0; ndx--) // ndx is element before last index
	{
		(*VH)->heap[ndx].link = ndx + 1; // link of ndx is ndx + 1
	}
}

void displayVirtualHeap(VHeap VH)
{
	int ndx;

	for (ndx = 0; ndx < SIZE; ndx++)
	{
		printf("%5d %-70s %5d", ndx, VH->heap[ndx].data, VH->heap[ndx].link);
		printf("\n");
	}
}

void initCursorList(cursorList *L, VHeap VH)
{
	L->elemPtr = -1; // indicate that first element is -1/list is empty
	L->VH = VH;		 // point to shared virtual heap
}

// insert
void insertFirst(cursorList *L, int group, char str[])
{
	int temp;
	temp = L->VH->availList;				   // temp is holding first index
	L->VH->availList = L->VH->heap[temp].link; // availList is now pointing to the next index
	strcpy(L->VH->heap[temp].data, str);	   // copy str to data
	L->VH->heap[temp].group = group;		   // group is now group
	L->VH->heap[temp].link = L->elemPtr;	   // link is now pointing to the first element
	L->elemPtr = temp;						   // first element is now temp
}

void populateList(cursorList *L)
{
	insertFirst(L, 1, "One day, Wayne woke up so early in the morning");
	insertFirst(L, 1, "He will go to TC for his DSA class");
	insertFirst(L, 2, "Two random classmates met together in their first day of class");
	insertFirst(L, 2, "They didn't know they were classmates till they sat next to each other. CRINGE BRO");
	insertFirst(L, 1, "But then he found out that no one was there");
}

void displayList(cursorList L)
{
	int *trav;
	if (L.elemPtr == -1)
	{
		printf("\nList is empty");
	}
	else
	{
		for (trav = &L.elemPtr; *trav != -1; trav = &L.VH->heap[*trav].link)
		{
			printf("\n %s", L.VH->heap[*trav].data);
		}
	}
}

cursorList getGroup(cursorList *L, int group)
{
	cursorList new = {-1, L->VH};
	int *trav, temp;
	for (trav = &L->elemPtr; *trav != -1;)
	{
		if (L->VH->heap[*trav].group == group)
		{
			temp = *trav;
			*trav = L->VH->heap[temp].link;
			L->VH->heap[temp].link = new.elemPtr;
			new.elemPtr = temp;
		}
		else
		{
			trav = &L->VH->heap[*trav].link;
		}
	}
	return new;
}
