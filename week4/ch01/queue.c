#include <stdio.h>
int enQueue(int *a,int rear,int data){
    a[rear]=data;
    rear++;
    return rear;
}
void deQueue(int *a,int front,int rear){
    //��� front==rear����ʾ����Ϊ��
    while (front!=rear) {
        printf("����Ԫ�أ�%d\n",a[front]);
        front++;
    }
}
int main() {
    int a[100];
    int front,rear;
    //���ö�ͷָ��Ͷ�βָ�룬��������û��Ԫ��ʱ����ͷ�Ͷ�βָ��ͬһ���ַ
    front=rear=0;
    //���
    rear=enQueue(a, rear, 1);
    rear=enQueue(a, rear, 2);
    rear=enQueue(a, rear, 3);
    rear=enQueue(a, rear, 4);
    //����
    deQueue(a, front, rear);
    return 0;
}
