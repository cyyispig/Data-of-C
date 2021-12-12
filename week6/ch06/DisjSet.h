#ifndef DisjSet_DisjSet_h
#define DisjSet_DisjSet_h
 
const int NumSets = 10;
 
/*
 * Disjoint Set ���ཻ�� / ���鼯
 * ��Ҫ����Ϊ�����Һͺϲ�
 */
typedef int DisjSet[NumSets + 1]; // Ϊ���±���룬�����趨�����СΪNumSets + 1����0��Ԫ����ռλ����
typedef int SetType; // ���ڵ㱣���Ԫ�ص�����
typedef int ElementType;
 
// ��ʼ��
void initialize(DisjSet set);
 
// �������Ĵ�С���ϲ��������ཻ����root1��root2�ֱ��ʾ����Ҫ�ϲ������ĸ�
void setUnion(DisjSet set, SetType root1, SetType root2);
 
// ����x����set�е��ĸ����ཻ��
SetType find(ElementType x, DisjSet set);
 
#endif
