#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define CONSTRAINT 10000

typedef struct {
    char s[CONSTRAINT];
    int top;
} Stack;

void
stackPush(Stack *st, const char *value)
{
    if (st->top >= CONSTRAINT) return;
    st->s[st->top++] = *value;
}

void
stackPop(Stack *st, char *popped)
{
    *popped = 0;
    if (st->top <= 0) return;
    *popped = st->s[--st->top];
}

bool
isValid(char *s)
{
    Stack *st = calloc(1, sizeof *st);
    assert(st);

    for(int i = 0; s[i] != '\0'; ++i) {
        char opener;
        switch (s[i]) {
            case ')':
                stackPop(st, &opener);
                if (opener != '(') {
                    free(st);
                    return false;
                }
                break;
            case ']':
                stackPop(st, &opener);
                if (opener != '[') {
                    free(st);
                    return false;
                }
                break;
            case '}':
                stackPop(st, &opener);
                if (opener != '{') {
                    free(st);
                    return false;
                }
                break;
            default:
                stackPush(st, &s[i]);
        }
    }

    int top = st->top;

    free(st);

    return top > 0 ? false : true;
}

int
main(void)
{
    bool r1, r2, r3, r4, r5, r6, r7;

    r1 = isValid("()");
    r2 = isValid("()[]{}");
    r3 = isValid("(]");
    r4 = isValid("([])");
    r5 = isValid("([)]");
    r6 = isValid("[");
    r7 = isValid("()))");

    printf("%s\n", r1 ? "true" : "false");
    printf("%s\n", r2 ? "true" : "false");
    printf("%s\n", r3 ? "true" : "false");
    printf("%s\n", r4 ? "true" : "false");
    printf("%s\n", r5 ? "true" : "false");
    printf("%s\n", r6 ? "true" : "false");
    printf("%s\n", r7 ? "true" : "false");

    return 0;
}
