#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CONSTRAINT 1000

int
getNumCols(char *s, int numRows)
{
    const int singleValueCols = numRows > 1 ? numRows - 2 : 0;
    int singleValueColFlag = 0;
    int res = 0;

    for (int len = strnlen(s, CONSTRAINT + 1); len > 0; ++res)
        if (!singleValueColFlag) {
            len -= numRows;
            singleValueColFlag = singleValueCols;
        } else {
            len -= 1;
            singleValueColFlag -= 1;
        }

    return res;
}

char *
convert(char *s, int numRows)
{
    const int length = strnlen(s, CONSTRAINT + 1);
    const int numCols = getNumCols(s, numRows);

    /* write matrix */
    int matrix[numCols][numRows];
    int index, zigZagFlag, significantRow;
    index = zigZagFlag = significantRow = 0;
    for (int x = 0; x < numCols; ++x)
        for (int y = 0; y < numRows; ++y) {
            if (index >= length) { // full string has already been written
                matrix[x][y] = EOF;
                continue;
            }

            if (zigZagFlag && y == significantRow) { // single-value column
                matrix[x][y] = s[index++];
                --significantRow;
            } else if (zigZagFlag && y != significantRow) matrix[x][y] = EOF;
            else matrix[x][y] = s[index++]; // full column

            if (y == numRows - 1 && numRows > 1) { // at bottom row of matrix
                if (!zigZagFlag) zigZagFlag = significantRow = y - 1;
                else if (zigZagFlag && significantRow == 0) zigZagFlag = 0;
            }
        }

    /* read matrix */
    char *res = calloc(CONSTRAINT + 1, sizeof *res);
    index = 0; // for writing characters to resultant string
    for (int y = 0; y < numRows; ++y)
        for (int x = 0; x < numCols; ++x)
            if (matrix[x][y] != EOF) res[index++] = matrix[x][y];
            else continue;

    return res;
}

int
main(void)
{
    char testStr[] = "PAYPALISHIRING";

    char *test1 = convert(testStr, 3);
    printf("%s\n", test1);
    free(test1);

    char *test2 = convert(testStr, 4);
    printf("%s\n", test2);
    free(test2);

    char *test3 = convert("A", 1);
    printf("%s\n", test3);
    free(test3);

    char me[] = "jacob-thompson";

    char *test4 = convert(me, 1);
    printf("%s\n", test4);
    free(test4);

    char *test5 = convert(me, 2);
    printf("%s\n", test5);
    free(test5);

    return 0;
}
