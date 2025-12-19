#include <stdio.h>

int
countOperations(int num1, int num2)
{
    int ops;

    for (ops = 0; num1 != 0 && num2 != 0 ; ++ops)
        if (num1 >= num2) num1 -= num2;
        else num2 -= num1;

    return ops;
}

int
main(void)
{
    int n = 10;
    int res = countOperations(n, n);

    printf("%d, %d -> %d\n", n, n, res);

    return 0;
}
