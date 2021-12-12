#include <stdio.h>
#include <stdlib.h>
#define SIZE 6
typedef struct {
    int rc;//��¼��
    int next;//ָ��������������У�����ֻ��Ҫ��¼��һ�������������λ�õ��±꼴�ɡ�
}SLNode;
typedef struct {
    SLNode r[SIZE];//�洢��¼������
    int length;//��¼��ǰ������
}SLinkListType;
//�������к���
void Arrange(SLinkListType *SL){
    //�� p ָ��ǰҪ���еļ�¼
    int p=SL->r[0].next;
    int i; 
    for (i=1; i<SL->length; i++) {
        //�������������֤��ԭ���������Ѿ��ƶ�����Ҫͨ�������� next ���ҵ���������λ��
        while (p<i) {
            p=SL->r[p].next;
        }
        //�ҵ�֮���� q ָ��ָ�����������һ����¼���ڵ�λ��
        int q=SL->r[p].next;
        //����������֤����Ҫͬ�±�Ϊ i �ļ�¼����λ�ý���
        if (p!=i) {
            SLNode t;
            t=SL->r[p];
            SL->r[p]=SL->r[i];
            SL->r[i]=t;
            //������ɺ󣬸ñ� next ��ֵ�����ں��ڱ���
            SL->r[i].next=p;
        }
        //����� p ָ����һ����¼
        p=q;
    }
}

int main(int argc, const char * argv[]) {

    SLinkListType *SL=(SLinkListType*)malloc(sizeof(SLinkListType));
    SL->length=6;
    SL->r[0].rc=0;
    SL->r[0].next=4;
   
    SL->r[1].rc=49;
    SL->r[1].next=3;
   
    SL->r[2].rc=38;
    SL->r[2].next=1;
   
    SL->r[3].rc=76;
    SL->r[3].next=0;
   
    SL->r[4].rc=13;
    SL->r[4].next=5;
   
    SL->r[5].rc=27;
    SL->r[5].next=2;
   
    Arrange(SL);
    int i;
    for (i=1; i<6; i++) {
        printf("%d ",SL->r[i].rc);
    }
    return 0;
}
