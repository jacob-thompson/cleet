#include <stdio.h>
#include <stdlib.h>

int
countOperations(int num1, int num2)
{
    for (int ops = 0; ; ++ops) {
        if (num1 == 0 || num2 == 0) return ops;

        if (num1 >= num2) {
            num1 -= num2;
        } else {
            num2 -= num1;
        }
    }
}

int
main(void)
{
    int num1, num2, res;
    num1 = 10;
    num2 = 10;
    res = countOperations(num1, num2);

    printf("%d, %d -> %d\n", num1, num2, res);

    return 0;
}
