#include <stdio.h>
#include <stdlib.h>
#define MAX 9
//������¼�Ľṹ��
typedef struct {
    int key;
}SqNote;
//��¼��Ľṹ��
typedef struct {
    SqNote r[MAX];
    int length;
}SqList;
//���� r[s]Ϊ�������������ɶѣ�����ÿ��������ֵ�����亢�ӽ���ֵ��
void HeapAdjust(SqList * H,int s,int m){
    SqNote rc=H->r[s];//�ȶԲ���λ���ϵĽ�����ݽ��б��棬���ú����ƶ�Ԫ�ض�ʧ��
    //���ڵ� s ����㣬ɸѡһֱ��Ҷ�ӽ�����
    int j; 
    for (j=2*s; j<=m; j*=2) {
        //�ҵ�ֵ���ĺ��ӽ��
        if (j+1<m && (H->r[j].key<H->r[j+1].key)) {
            j++;
        }
        //�����ǰ�������ĺ��ӽ���ֵ��������Ҫ�Դ˽�����ɸѡ��ֱ���Թ�
        if (!(rc.key<H->r[j].key)) {
            break;
        }
        //�����ǰ����ֵ�Ⱥ��ӽ��������ֵС��������ֵ�����ý�㣬���� rc ��¼�Ÿý���ֵ�����Ըý���ֵ���ᶪʧ
        H->r[s]=H->r[j];
        s=j;//s�൱��ָ������ã�ָ���亢�ӽ�㣬��������ɸѡ
    }
    H->r[s]=rc;//�����轫rc��ֵ��ӵ���ȷ��λ��
}
//����������¼��λ��
void swap(SqNote *a,SqNote *b){
    int key=a->key;
    a->key=b->key;
    b->key=key;
}
void HeapSort(SqList *H){
    //�����ѵĹ���
    int i;
    for (i=H->length/2; i>0; i--) {
        //�����к��ӽ��ĸ�������ɸѡ
        HeapAdjust(H, i, H->length);
    }
    //ͨ�����ϵ�ɸѡ�����ֵ��ͬʱ���ϵؽ���ɸѡʣ��Ԫ��
    for (i=H->length; i>1; i--) {
        //�������̣���Ϊ��ѡ�������ֵ���б���������ͬʱ�����λ���ϵ�Ԫ�ؽ����滻��Ϊ��һ��ɸѡ��׼��
        swap(&(H->r[1]), &(H->r[i]));
        //����ɸѡ�����ֵ�Ĺ���
        HeapAdjust(H, 1, i-1);
    }
}

int main() {
    SqList * L=(SqList*)malloc(sizeof(SqList));
    L->length=8;
    L->r[1].key=49;
    L->r[2].key=38;
    L->r[3].key=65;
    L->r[4].key=97;
    L->r[5].key=76;
    L->r[6].key=13;
    L->r[7].key=27;
    L->r[8].key=49;
    HeapSort(L);
    int i;
    for (i=1; i<=L->length; i++) {
        printf("%d ",L->r[i].key);
    }
    return 0;
}
