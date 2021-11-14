#include <stdio.h>
int isPrime(unsigned int N);
int main(){
	int N;
	printf("������һ������:");
	scanf("%d",&N);
	if (isPrime(N))
		printf("N=%d ������\n", N);
	else
		printf("N=%d ��������\n", N);
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
