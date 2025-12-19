#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int
myAtoi(char *s)
{
    intmax_t res = 0;
    bool reading = false;
    bool inv = false;

    for (; *s != 0 && res < INT32_MAX; ++s) {
        if (isalpha(*s) || *s == '.' || (reading && !isdigit(*s))) break;

        if (isdigit(*s)) {
            reading = true;
            res *= 10;
            res += *s - '0';
        } else if (*s == '-') {
         reading = true;
         inv = true;
        } else if (*s == '+') {
         reading = true;
         inv = false;
        } else if (*s == ' ') continue;
    }

    if (inv) res = -res;

    if (res < INT32_MIN) res = INT32_MIN;
    else if (res > INT32_MAX) res = INT32_MAX;

    return res;
}

int
main(void)
{
    printf("%d\n", myAtoi("-91283472332"));
    printf("%d\n", myAtoi("+-12"));
    printf("%d\n", myAtoi("1337c0d3"));
    printf("%d\n", myAtoi("0-1"));
    printf("%d\n", myAtoi("words and 987"));

    return 0;
}
