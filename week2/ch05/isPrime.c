#include <stdio.h>
int isPrime(unsigned int N);
int main(){
	int N;
	printf("请输入一个数字:");
	scanf("%d",&N);
	if (isPrime(N))
		printf("N=%d 是素数\n", N);
	else
		printf("N=%d 不是素数\n", N);
	return 0;
}
int isPrime(unsigned int N)
{
    if (N == 1)
        return 0;
    if (N % 2 == 0)
        return 0;
	int i;
    for (i = 3; i*i <= N; i += 2)
    {
        if (N % i == 0)
            return 0;
    }
    return 1;
}
