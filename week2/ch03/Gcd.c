#include <stdio.h>

int Gcd(int i,int j);
int main(){
	int first,second;
	printf("���������������->\n�������һ����:");
	scanf("%d",&first);
	printf("������ڶ�����:");
	scanf("%d",&second);
	int result = Gcd(first,second);
	printf("���������:%d",result);
} 
int Gcd(int i,int j){
	int temp;
	while (j>0){
    	temp=i%j;
    	i=j;
    	j=temp;
	}
	return i;
}
