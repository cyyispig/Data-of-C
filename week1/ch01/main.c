#include  <stdio.h>
int main(){
	void sort(int array[],int length);
	
	int N = 10;
	int k;
	int array[10] = {1,5,2,76,23,74,67,36,98,64};
	printf("一共有%d个数字\n",N);
	printf("请输入需要第几大的值K=");
	scanf("%d",&k);
	sort(array,N);
	int i;
	
	for(i = 0;i < 10;i++){
		printf("%d  ",array[i]);
	}
	
	printf("\nk:%d",array[k-1]);
}

void sort(int array[],int length){	
	int temp = 0,i,j;	
	for (j = 0;j < length-1;j++)  
    {                           
        for (i = 0;i < length-1-j;i++)
        {
            if(array[i] <= array[i+1])  
            {
                temp = array[i];     
                array[i] = array[i+1];  
                array[i+1] = temp;
            }
        }
    }	
} 
