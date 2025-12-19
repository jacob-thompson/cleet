#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int *
setOfPerfectSquares(int max)
{
    uint32_t x = 1;
    int *set = calloc(max, sizeof *set);
    assert(set);

    for (int i = 0; x * x <= (unsigned)max; ++x) set[i++] = x * x;

    return set;
}

int
mySqrt(int x)
{
    if (x == 0 || x == 1) return x;

    const int *squares = setOfPerfectSquares(x);
    int res;

    for (int i = 0; squares[i] != 0; ++i) res = i + 1;

    free((void *)squares);

    return res;
}

int
main(void)
{
    printf("%d\n", mySqrt(2));
    printf("%d\n", mySqrt(4));
    printf("%d\n", mySqrt(8));
    printf("%d\n", mySqrt(25));
    printf("%d\n", mySqrt(125));
    printf("%d\n", mySqrt(2147395600));

    return 0;
}
