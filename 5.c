#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
isPalindrome(char *s, int front, int back)
{
    for (; front < back; ++front, --back)
        if (s[front] != s[back]) return 0;
    return 1;
}

char *
longestPalindrome(char *s)
{
    int longest = 1;
    int start = 0;

    for (int i = 0; s[i] != 0; ++i) {
        for (int j = 0; s[j] != 0; ++j) {
            if (s[i] == s[j] && isPalindrome(s, i, j)) {
                int len = j + 1 - i;
                if (len > longest) {
                    longest = len;
                    start = i;
                }
            }
        }
    }

    char *res = calloc(longest + 1, sizeof *res);
    if (!res) return NULL;

    strncpy(res, s + start, longest);
    *(res + longest) = '\0';

    return res;
}

int
main(void)
{
    char *res1 = longestPalindrome("babad");
    printf("%s\n", res1);
    free(res1);

    char *res2 = longestPalindrome("cbbd");
    printf("%s\n", res2);
    free(res2);

    return 0;
}
