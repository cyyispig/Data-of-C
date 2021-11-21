#include <stdio.h>
#include <malloc.h>
 
typedef int ElemType;
typedef struct Node {
	int data;
	struct Node* next;
}Node, *List;

int InitList(List *list, ElemType* arr, int num)
{
	int i= 0;
	Node* tail_node; 
	Node* tmp_node;
	*list =(List)malloc(sizeof(Node));
	if(NULL == *list)
		return;
	(*list)->data = arr[i];
	(*list)->next = NULL;
	tail_node = *list;
	for(i = 1; i < num; i++) {
		tmp_node = (Node*)malloc(sizeof(Node));
		if(NULL == tmp_node)
			return;
		tmp_node->data = arr[i];
	        tmp_node->next = NULL;
		tail_node->next = tmp_node;
		tail_node = tmp_node;	
	}
}	
 
void TraveseList(List list)
{
	Node* tmp_node;
	if(NULL == list)
		return;
	tmp_node = list;
	while(tmp_node) {
		printf("%d ", tmp_node->data);
		tmp_node = tmp_node->next;
	}
	printf("\n");
}
 
void ReverseList(List* list)
{
	Node* p_pre = NULL;
	Node* p_cur = NULL;
	Node* p_nxt = NULL;
	if(NULL == list)
		return;
	p_cur = (*list)->next;
	p_pre = *list;
	p_pre->next = NULL;
	while(p_cur) {
		p_nxt = p_cur->next;
		p_cur->next = p_pre;
		p_pre = p_cur;
		p_cur = p_nxt;
	}
	*list = p_pre;
}
 
Node* Reverse2Point(List* head) 
{
	Node* p_cur = NULL;
	Node* p_nxt = NULL;
	if(NULL == *head)
		return;
	p_cur = (*head)->next;
	(*head)->next = NULL;
	while(p_cur) {
		p_nxt = p_cur->next;
		p_cur->next = *head;
		*head = p_cur;
		p_cur = p_nxt;
	}
}
Node* Reverse(Node* p_cur, Node* p_pre)
{
	if(NULL == p_cur->next) {
		p_cur->next = p_pre;
		return p_cur;
	}
	else {
		Node *p_nxt = p_cur->next;
		p_cur->next = p_pre;
		Reverse(p_nxt, p_cur);
	}
}
 
int main()
{
	List head;
	Node* tmp;
	int array[] = {3, 5, 7, 8, 2};
	InitList(&head, array, 5);
	TraveseList(head);
	//三种不同的翻转方法 
	printf("reverse list:");
	ReverseList(&head);
	TraveseList(head);
	
	printf("reverse list:");
	head = Reverse(head, NULL);
	TraveseList(head);
	
	printf("reverse list:");
	Reverse2Point(&head);
	TraveseList(head);
	return 0;
}
