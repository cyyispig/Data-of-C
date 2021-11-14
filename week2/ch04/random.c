#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
int fillArray(int A[], int n);
int randInt(int i, int j);
int main()
{
	int i,n;
	printf("请确认数组大小:");
	scanf("%d",&n);
	int array[n];
	fillArray(array,n);
	printf("无序数组结果:");
	for(i = 0;i < n;i++){
		printf("%d " ,array[i]);
	}
}
int fillArray(int A[], int n)
{
	int count, ran, k;
    count = 0;
    while (count < n){
    	ran = randInt(1, n+1);
        for (k = 0; k < count; k++){
        	if (A[k] == ran)
                 break;
        }
        if (k == count){
            A[count] = ran;
            count++;
    	}
	}
     return 1;
}
int randInt(int i, int j){
	if (j - i == 0)
        return i;
    else if (j - i < 0)
        return 0;
    else
        return rand() % (j - i) + i;
}
