#include <stdio.h>
int BinarySearch(int* nums, int numsSize,int target);
int main(){
	int array[9] = {12,23,45,56,78,89,100,123,125};
	printf("��������Ϊ:");
	int i;
	for(i = 0;i < 9;i++){
		printf("%d " ,array[i]);
	}
	printf("\n������Ҫ�ҵ�����:");
	int target;
	scanf("%d",&target);
	int result = BinarySearch(array,9,target);
	if(result == -1){
		printf("�����ֲ����ڣ�");
	}
	else{
		printf(("�������±�Ϊ:%d\n"),result);	
	}
}
int BinarySearch(int* nums, int numsSize,int target){
	int left = 0;
	int right = numsSize - 1;
	while(left <= right){
		int mid = (left + right)/2;
		if(nums[mid] == target){
			return mid+1;
		}
		else if (nums[mid] > target) {
                right = mid - 1;
        }else {
            left = mid + 1;
        }
	}
	return -1;
}
