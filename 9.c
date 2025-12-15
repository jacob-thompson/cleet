#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define CONSTRAINT 11

bool
isPalindrome(int x)
{
    if (x < 0) return false;

    char front[CONSTRAINT], *back;
    snprintf(front, CONSTRAINT, "%d", x);
    back = front + strnlen(front, CONSTRAINT) - 1;

    for (int i = 0; front + i < back; ++i, --back)
        if (front[i] != *back) return false;

    return true;
}

int
main(void)
{
    int test1 = 121;
    printf("%d is %s.\n", test1, isPalindrome(test1) ? "a pal" : "not a pal");

    int test2 = -121;
    printf("%d is %s.\n", test2, isPalindrome(test2) ? "a pal" : "not a pal");

    int test3 = 10;
    printf("%d is %s.\n", test3, isPalindrome(test3) ? "a pal" : "not a pal");

    int test4 = 101024;
    printf("%d is %s.\n", test4, isPalindrome(test4) ? "a pal" : "not a pal");

    return 0;
}
