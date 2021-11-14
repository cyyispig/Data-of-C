#include <stdio.h>

int maxSubArray(int* nums, int numsSize);

int main(){
	int array[9] = {-2,1,-3,4,-1,2,1,-5,4};
	printf("��������Ϊ:");
	int i;
	
	for(i = 0;i < 9;i++){
		printf("%d " ,array[i]);
	}
	printf(("\n\n��������к�Ϊ:%d\n"),maxSubArray(array,9));	
}

int maxSubArray(int* nums, int numsSize) {
    int pre = 0, maxAns = nums[0];
    int i ;
    for (i = 0; i < numsSize; i++) {
        pre = fmax(pre + nums[i], nums[i]);
        maxAns = fmax(maxAns, pre);
    }
    return maxAns;
}

