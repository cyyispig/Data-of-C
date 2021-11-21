#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct Node { 
	int coefficient;
	int exponent;
	struct Node* pNext;
}PolyNode,*PtrPolyNode;
typedef PtrPolyNode Polynomial;

Polynomial createPolynomial_1(void); //创建多项式1
Polynomial createPolynomial_2(void); //创建多项式2
PtrPolyNode newNode(PtrPolyNode pTail, int Coeff, int Exponent);
Polynomial addPolynomial(Polynomial poly1, Polynomial poly2);//将两个多项式相加
void showPolynomial(Polynomial poly);//次数从高到低输出多项式的系数

int main(void) {
	printf("书上的例子\n\n");
	Polynomial P1 = createPolynomial_1(); //多项式1
	showPolynomial(P1);
	
	Polynomial P2 = createPolynomial_2(); //多项式2
	showPolynomial(P2);

	Polynomial P = addPolynomial(P1, P2);
	showPolynomial(P);

	return 0;
}

Polynomial createPolynomial_1(void) {//创建多项式1

	Polynomial P = (Polynomial)malloc(sizeof(PolyNode) * 3);//P为头节点
	if (P == NULL) {
		printf("内存分配失败！\n");
		exit(-1);
	}
	else 
		P->pNext = NULL;
	PtrPolyNode pTail = P;
	pTail = newNode(pTail, 10, 1000);
	pTail = newNode(pTail, 5, 14);
	pTail = newNode(pTail, 1, 0);

	return P;
}
Polynomial createPolynomial_2(void) {//创建多项式2
	Polynomial P = (Polynomial)malloc(sizeof(PolyNode) * 4);//P为头节点
	
	if (P == NULL) {
		printf("内存分配失败！\n");
		exit(-1);
	}
	else
		P->pNext = NULL;
		
	PtrPolyNode pTail = P;
	pTail = newNode(pTail, 3, 1990);
	pTail = newNode(pTail, -2, 1492);
	pTail = newNode(pTail, 11, 1);
	pTail = newNode(pTail, 5, 0);

	return P;
}
PtrPolyNode newNode(PtrPolyNode pTail, int Coeff, int Exponent) {
	
	PtrPolyNode pNew = (PtrPolyNode)malloc(sizeof(PolyNode));
	if (pNew == NULL) {
		printf("内存分配失败！\n");
		exit(-1);
	}
	else {
		pNew->coefficient = Coeff;
		pNew->exponent = Exponent;
		pNew->pNext = NULL;
		pTail->pNext = pNew;
		pTail = pNew;
	}
	return pTail;

}
Polynomial addPolynomial(Polynomial poly1, Polynomial poly2) {//将两个多项式相加

	Polynomial P = (Polynomial)malloc(sizeof(PolyNode) * 3);//P为进行加法后的多项式
	if (P == NULL) {
		printf("内存分配失败！\n");
		exit(-1);
	}
	else
		P->pNext = NULL;
	PtrPolyNode pTail = P;

	PtrPolyNode p = poly1->pNext;
	PtrPolyNode q = poly2->pNext;
	while (p != NULL && q!=NULL) {
		if (p->exponent > q->exponent) {
			pTail = newNode(pTail, p->coefficient, p->exponent);
			p = p->pNext;
		}
		if (p->exponent < q->exponent) {
			pTail = newNode(pTail, q->coefficient, q->exponent);
			q = q->pNext;
		}
		if (p->exponent == q->exponent) {
			pTail = newNode(pTail, p->coefficient + q->coefficient, p->exponent);
			p = p->pNext;
			q = q->pNext;
		}
	}

	return P;

}
void showPolynomial(Polynomial poly) {//次数从高到低输出多项式的系数
	
	PtrPolyNode p = poly->pNext;
	if (p == NULL) {
		printf("链表为空！\n");
		return;
	}
	while (p != NULL) {
		printf("%dx^%d", p->coefficient, p->exponent);
		if (p->pNext != NULL)
			printf(" + ");

		p = p->pNext;
	}
	printf("\n");
}

