#include <stdio.h>
#include <stdlib.h>
typedef struct student {
    int data;
    struct student *next;
}Node;
 
int main()
{
    int n;
    printf("�����빲����Ԫ��:");
    scanf("%d",&n);
    Node *p1,*p2,*head;
    int i,m;
    p1=(Node *)malloc(sizeof(Node ));
    p2=p1;
    head=p1;
    printf("��1Ԫ��:");
    scanf("%d",&p1->data);
    for(i=0;i<n-1;i++){
        p1=(Node *)malloc(sizeof(Node ));
        printf("��%dԪ��:",i+2);
        scanf("%d",&p1->data);
        p2->next=p1;
        p2=p1;
    }
    p2->next=NULL;
	printf("Ҫ���Ǹ�Ԫ�أ�");
    scanf("%d",&m);
    Node *p=head;
    int count=1;
    while(p!=NULL){
        if(p->data==m){
            break;
        }
        else {
            p=p->next;
            count++;
        }
    }
    if(count==n+1){
        printf("δ�ҵ���Ԫ�أ�");
    }
    else {
        printf("��Ԫ��������ĵ�%d��",count);
    }
 
    return 0;
}
