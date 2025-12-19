#include <stdint.h>
#include <stdio.h>

#define MAX_DIGITS 10

const int min[] = {-2, -1, -4, -7, -4, -8, -3, -6, -4, -8};
const int max[] = {2, 1, 4, 7, 4, 8, 3, 6, 4, 7};

int
countDigits(int n)
{
    if (n == 0) return 1;
    int count = 0;
    for (; n != 0; n /= 10) ++count;
    return count;
}

int
reverse(int x)
{
    const int amountOfDigits = countDigits(x);
    if (amountOfDigits > MAX_DIGITS) return 0;

    int care = amountOfDigits == MAX_DIGITS;

    const int neg = x < 0;
    const int *cmp = neg ? min : max;

    int res, digit;
    res = 0;

    for (int i = 0; x != 0; x /= 10) {
        digit = x % 10;

        if (care) {
            if (!neg && digit < cmp[i]) care = 0;
            else if (neg && digit > cmp[i]) care = 0;

            if (!neg && digit > cmp[i]) return 0;
            else if (neg && digit < cmp[i]) return 0;

            ++i;
        }

        res *= 10;
        res += digit;
    }

    return res;
}

int
main(void)
{
    printf("123 -> %d\n", reverse(123));
    printf("-123 -> %d\n", reverse(-123));
    printf("120 -> %d\n", reverse(120));
    printf("min: %d -> %d\n", INT32_MIN, reverse(INT32_MIN));
    printf("%d -> %d\n", INT32_MIN + 1, reverse(INT32_MIN + 1));
    printf("max: %d -> %d\n", INT32_MAX, reverse(INT32_MAX));
    printf("%d -> %d\n", INT32_MAX - 1, reverse(INT32_MAX - 1));
    printf("-2147483412 -> %d\n", reverse(-2147483412));

    return 0;
}
