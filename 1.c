#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int *
twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int *result = calloc(2, sizeof *result);
    assert(result);

    for (int i = 0; i < numsSize; ++i)
        for (int j = i + 1; j < numsSize; ++j)
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }

    return NULL;
}

int
main(void)
{
    int nums[] = {3, 2, 4};
    int size = 3;
    int target = 6;

    int *rSize = calloc(1, sizeof(int));
    assert(rSize);
    int *res = twoSum(nums, size, target, rSize);

    if(res == NULL || rSize == 0) return 1;

    printf("[%d,%d]\n", res[0], res[1]);
    free(rSize);
    free(res);

    return 0;
}
