#include <stdio.h>
#include <limits.h>

double
findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    int totalSize = nums1Size + nums2Size;
    int merged[totalSize];
    int oddSize = totalSize % 2 != 0;

    int i, i1, i2;
    for (i = i1 = i2 = 0; i < totalSize; ++i) {
        int curr1 = i1 >= nums1Size ? INT_MAX : *(nums1 + i1);
        int curr2 = i2 >= nums2Size ? INT_MAX : *(nums2 + i2);
        merged[i] = curr1 <= curr2 ? *(nums1 + i1++) : *(nums2 + i2++);

        if (oddSize && i == (int)((totalSize - 1) / 2))
            return merged[i];

        if (!oddSize && i == (int)(totalSize / 2))
            return (double)(merged[i - 1] + merged[i]) / 2;
    }

    return 0;
}

int
main(void)
{
    int nums1[] = {1, 2};
    int nums2[] = {3, 4};

    printf("%f\n", findMedianSortedArrays(nums1, 2, nums2, 2));

    return 0;
}
