#include <stdio.h>
#include <stlidb.h>

typedef struct
{
    char data;
    int link;
} node;

typedef struct
{
    node Nodes[Max];
    int Avail;
} VirtuallHeap;

typedef int List;

void InitializeVH(VirtualHeap *VH);
void insertFirst(VirtualHeap *VH, char data);
int allocSpace(VirtualHeap *VH);
void deallocSpace(VirtualHeap *VH, int node);
void deleteElement(VirtualHeap *VH, int node);

int main()
{
    VirtualHeap VH;
    InitializeVH(&VH);
    return 0;
}

void InitializeVH(VirtualHeap *VH)
{
    int i;
    for (i = 0; i < Max - 1; i++)
    {
        VH->Nodes[i].link = i + 1;
    }
    VH->Nodes[Max - 1].link = -1;
    VH->Avail = 0;
}

int allocSpace(VirtualHeap *VH)
{
    int node;
    if (VH->Avail != -1)
    {
        node = VH->Avail;
        VH->Avail = VH->Nodes[VH->Avail].link;
    }
    return node;
}

int deallocSpace(VirtualHeap *VH, int node)
{
}

void insertFirst(VirtualHeap *VH, char data)
{
    int node = allocSpace(VH);
    if (node != -1)
    {
        VH->Nodes[node].data = data;
        VH->Nodes[node].link = VH->Avail;
        VH->Avail = node;
    }
}

void deleteElement(VirtualHeap *VH, int node)
{
    deallocSpace(VH, node);
}