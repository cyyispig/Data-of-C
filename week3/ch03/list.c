#include <stdio.h>
#include <stdlib.h>
#include "list.h"

static void FataError(char *S);
void FataError(char *S)
{
        fputs("S\n",stderr);
        exit(EXIT_FAILURE);
}



List MakeEmpty(List L)
{
        Position P;
        P=(Position)malloc(sizeof(struct Node));
        P->Next=P;
        return P;
}


int IsEmpty(List L){
        return L->Next==L;
}

int IsLast(Position P,List L){
        return P->Next==L;
}

Position Find(ElementType X,List L){
        Position P;
        P=L->Next;
        while(P!=L&&P->Element!=X)
                P=P->Next;
        return P;
}

void Delete(ElementType X,List L){
        Position P,TmpCell;
        P=FindPrevious(X,L);
        if(!IsLast(P,L))
        {
                TmpCell=P->Next;
                P->Next=TmpCell->Next;
                free(TmpCell);
        }
        else
        {
                TmpCell=L->Next;
                L->Next=TmpCell->Next;
                free(TmpCell);
        }
}


Position FindPrevious(ElementType X,List L){
        Position P;
        P=L;
        while(P->Next!=L&&P->Next->Element!=X)
                P=P->Next;
        if(P==L)
        {
                while(!IsLast(P,L))
                        P=Advance(P,L);
        }
        return P;
}


void Insert(ElementType X,List L,Position P){
        Position TmpCell;
        TmpCell=malloc(sizeof(struct Node));
        if(TmpCell==NULL)
                FataError("Out of space!!");
        TmpCell->Element=X;
        TmpCell->Next=P->Next;
        P->Next=TmpCell;
}


void DeleteList(List L){
        Position P,Tmp;
        P=L->Next;
        L->Next=NULL;
        while(P!=L)
        {
                Tmp=P->Next;
                free(P);
                P=Tmp;
        }
}

Position Header(List L){
        return L;
}

Position First(List L){
        return L->Next;
}

Position Advance(Position P,List L){
        if(IsLast(P,L))
                return P->Next->Next;
        return P->Next;
}

ElementType Retrieve(Position P){
        return P->Element;
}

void PrintList(List L){
        Position P;
        P=L->Next;
        if(IsEmpty(L))
                FataError("List is empty!!!");
        while(P!=L)
        {
                printf("%-5d",P->Element);
                P=P->Next;
        }
}

