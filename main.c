#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Set the return size.
    *returnSize = 2;

    // We loop through the nums.
    for (int x = 0; x < numsSize; x++) {
        for (int y = numsSize - 1; y > x; y--) {
            if ((nums[x] + nums[y]) == target) {
                int *r_nums = malloc(sizeof(int) * 2);
                r_nums[0] = x;
                r_nums[1] = y;
                return r_nums;
            }
        }
    }

    return NULL;
}


int main(int argc, char *argv[])
{

    // int nums[4] = {2,7,11,15};
    int nums[3] = {3,2,4};
    // int nums[3] = {1,2,3};
    int returnSize = sizeof(int) * 2;

    int *result = twoSum(nums, 3, 6, &returnSize);

    printf("Number A %u \n", result[0]);
    printf("Number B %u \n", result[1]);

    return EXIT_SUCCESS;
}
