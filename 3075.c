#include <stdio.h>
#include <stdlib.h>

int
compareInts(const void *a, const void *b)
{
    int aInt = *((int *)a);
    int bInt = *((int *)b);

    if (aInt > bInt) return -1;
    else if (aInt < bInt) return 1;
    else return 0;
}

long long
maximumHappinessSum(int *happiness, int happinessSize, int k)
{
    long long sum = 0;

    /* sort queue by descending order */
    qsort(happiness, happinessSize, sizeof(int), compareInts);

    for (int i = 0; k > 0; ++i, --k) {
        int curr = happiness[i] - i;
        if (curr > 0) sum += curr;
    }

    return sum;
}

int
main(void)
{
    int test1[] = {2, 3, 4, 5};

    printf("%lld\n", maximumHappinessSum(test1, 4, 1));

    int test2[] = {12, 1, 42};

    printf("%lld\n", maximumHappinessSum(test2, 3, 3));

    return 0;
}
