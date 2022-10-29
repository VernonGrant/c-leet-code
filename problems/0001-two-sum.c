#include <stdio.h>
#include <stdlib.h>

/*
    Given an array of integers nums and an integer target, return indices of the
    two numbers such that they add up to target.

    You may assume that each input would have exactly one solution, and you may not
    use the same element twice.

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

    Constraints:
    2 <= nums.length <= 104
    -109 <= nums[i] <= 109
    -109 <= target <= 109
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSumAlt(int* nums, int numsSize, int target, int* returnSize) {
    // Set some defaults.
    int x = 0;
    int y = numsSize - 1;

    // Set the return size.
    *returnSize = 2;

    while (x < y) {
        // target was found.
        if ((nums[x] + nums[y]) == target) {
            int *r_nums = malloc(sizeof(int) * 2);
            r_nums[0] = x;
            r_nums[1] = y;
            return r_nums;
        }

        if ((y - 1) == x) {
            y = numsSize - 1;
            x++;
            continue;
        }

        y -= 1;
    }

    return NULL;
}

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

    int nums[3] = {3,2,4};
    int returnSize = sizeof(int) * 2;
    int *result = twoSum(nums, 3, 6, &returnSize);

    printf("Number A %u \n", result[0]);
    printf("Number B %u \n", result[1]);

    return EXIT_SUCCESS;
}
