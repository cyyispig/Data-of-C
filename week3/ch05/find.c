#include <stdio.h>
#include <stdlib.h>
typedef struct student {
    int data;
    struct student *next;
}Node;
 
int main()
{
    int n;
    printf("请输入共多少元素:");
    scanf("%d",&n);
    Node *p1,*p2,*head;
    int i,m;
    p1=(Node *)malloc(sizeof(Node ));
    p2=p1;
    head=p1;
    printf("第1元素:");
    scanf("%d",&p1->data);
    for(i=0;i<n-1;i++){
        p1=(Node *)malloc(sizeof(Node ));
        printf("第%d元素:",i+2);
        scanf("%d",&p1->data);
        p2->next=p1;
        p2=p1;
    }
    p2->next=NULL;
	printf("要找那个元素？");
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
        printf("未找到该元素！");
    }
    else {
        printf("此元素在链表的第%d个",count);
    }
 
    return 0;
}
