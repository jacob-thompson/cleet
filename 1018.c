#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool *
prefixesDivBy5(int* nums, int numsSize, int* returnSize)
{
    bool *output = calloc(numsSize, sizeof *output);

    unsigned long int current = 0;

    for (int i = 0; i < numsSize; ++i) {
        current <<= 1;
        if (nums[i] == 1)
            ++current;

        current %= 5;
        if (current == 0) {
            *(output + i) = true;
        } else {
            *(output + i) = false;
        }
    }

    *returnSize = numsSize;

    return output;
}

int
main(void)
{
    int nums[] = {
        1,0,1,1,1,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,1,1,1,
        1,0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,1,0,0,1,1,1,
        1,1,1,0,1,1,0,1,0,0,0,0,0,0,1,0,1,1,1,0,0,1,0
    };
    int nsize = (sizeof nums) / sizeof(int);
    int rsize;

    bool *result = prefixesDivBy5(nums, nsize, &rsize);

    printf("[");
    for (int i = 0; i < rsize; ++i)
        printf("%s,", result[i] == 1 ? "true" : "false");
    printf("\b]\n");

    free(result);
    return 0;
}
