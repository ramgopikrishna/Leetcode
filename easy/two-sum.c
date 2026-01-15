/* SUM OF TWO 
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *ret = (int*)malloc(2*(sizeof(int)));
    *returnSize = sizeof(ret) / sizeof(int);
    for(int x=0; x<numsSize; x++)
    {
        for(int y=x+1; y<numsSize; y++)
        {
            if(nums[x]+nums[y]==target)
            {
               ret[0]=x;
               ret[1]=y;
               return ret;         
            }
        }
    }   
    return NULL;
}

int main(void)
{
	int nums[] = {2,7,11,15};
	int numsSize = (sizeof(nums) / sizeof(int));
	int target = 17;
	int *returnSize = (int *)malloc(sizeof(int));
	int *result = twoSum(nums, numsSize, target, returnSize);
	if(result)
	{
		printf("RAMA %d\n", result[0]);
		printf("RAMA %d\n", result[1]);
	}
}
