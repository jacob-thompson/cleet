#include <stdio.h>

#define MAX_N 45

int memo[MAX_N + 1] = {0};

int
climbStairs(int n)
{
    if (n == 1 || n == 2) return n;
    if (memo[n]) return memo[n];

    memo[n] = climbStairs(n - 1) + climbStairs(n - 2);

    return memo[n];
}

int
main(void)
{
    printf("n = 2 -> %d\n", climbStairs(2));
    printf("n = 3 -> %d\n", climbStairs(3));
    printf("n = 4 -> %d\n", climbStairs(4));
    printf("n = 5 -> %d\n", climbStairs(5));
    printf("n = 45 -> %d\n", climbStairs(45));

    return 0;
}
