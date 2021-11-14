#include <stdio.h>

int Gcd(int i,int j);
int main(){
	int first,second;
	printf("求两个数最大公因数->\n请输入第一个数:");
	scanf("%d",&first);
	printf("请输入第二个数:");
	scanf("%d",&second);
	int result = Gcd(first,second);
	printf("最大公因数是:%d",result);
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
