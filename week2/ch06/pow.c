#include<stdio.h>
int Pow(int x, int n);
int main(void)
{
	int x; 
	int n;
	printf("请输入底数:");
	scanf("%d",&x);
	printf("请输入指数:");
	scanf("%d",&n);
	printf("结果为:%d\n", Pow(x, n));
	return 0;
}
int Pow(int x, int n)
{
	if (n == 0)
		return 1;
	int temp = x;
	while (n != 1)
	{
		if (n % 2 == 0){
			temp = temp * temp;
			n = n / 2;
		}
		else{
			temp = x * temp * temp;
			n = n / 2;
		}
	}
	return temp;
}

