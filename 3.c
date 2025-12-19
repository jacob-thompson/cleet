#include <stdio.h>

#define ASCII_VALUES 128

int
lengthOfLongestSubstring(char *s)
{
    int longest = 0;
    int set[ASCII_VALUES] = {0};

    char *left, *right;
    left = right = s;

    for (int i = 0; *(s + i) != '\0'; ++i) {
        char *curr = s + i;

        ++set[(unsigned)*curr];
        right = curr;

        if (set[(unsigned)*curr] > 1) {
            while (*left != *curr) {
                set[(unsigned)*left] = 0;
                ++left;
            };

            ++left;

            continue;
        }

        const int len = right - left + 1;
        if (len > longest) longest = len;
    }

    return longest;
}

int
main(void)
{
    int res;

    char one[] = "abcabcbb";
    res = lengthOfLongestSubstring(one);
    printf("%d\n", res);

    char two[] = "bbbbb";
    res = lengthOfLongestSubstring(two);
    printf("%d\n", res);

    char three[] = "pwwkew";
    res = lengthOfLongestSubstring(three);
    printf("%d\n", res);

    char four[] = "tmmzuxt";
    res = lengthOfLongestSubstring(four);
    printf("%d\n", res);

    char five[] = "aab";
    res = lengthOfLongestSubstring(five);
    printf("%d\n", res);

    return 0;
}
