#include <stdio.h>
#include "list.h"
int main(void){
    int M,N,i,j,count;
    List L;
    Position P,Temp;
    L=MakeEmpty(L);
    puts("M   N:");
    scanf("%d%d",&M,&N);
    for(i=1,P=L;i<=N;i++){
            Insert(i,L,P);
            P=Advance(P,L);
    }
    PrintList(L);
    putchar('\n');
    P=L->Next;
    for(count=0;count<N-1;count++){
        for(j=M;j>0;j--){
                P=Advance(P,L);
        }
        printf("%5d",Retrieve(P));
        Temp=P;
        P=Advance(P,L);
    	Delete(Retrieve(Temp),L);
}
    PrintList(L);
    return 0;
}

