#include  <stdio.h>
int main(){
	void BubbleSort(int array[],int length);
	void InsertSort(int array[]); 
	
	int N = 10;
	int k;
	int array[10] = {1,5,2,76,23,74,67,36,98,64};
	printf("һ����%d������\n",N);
	printf("��������Ҫ�ڼ����ֵK=");
	scanf("%d",&k);
	printf("ð���������");
	BubbleSort(array,N);
	int i;

	printf("\nk:%d\n",array[k-1]);
	printf("�����������");
	InsertSort(array);
	printf("\nk:%d\n",array[k-1]);
}
//ð������O(n*n)
void BubbleSort(int array[],int length){	
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
	for(i=0;i<10;i++){
		printf("%d ",array[i]);
	}	
}
//����
//��������O(n*n)
void InsertSort(int array[]){
	int i,j,k;
	for(j=0;j<10;j++){
		k=array[j];
		for(i=j-1;i>=0&&array[i]<k;i--){
			array[i+1]=array[i];
		}
	array[i+1]=k;
	}
	for(i=0;i<10;i++){
		printf("%d ",array[i]);
	}
}
