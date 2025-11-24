#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define CONSTRAINT 10000

struct stack {
    char s[CONSTRAINT];
    int top;
};

void
stackPush(struct stack *stack, const char *value)
{
    if (stack->top >= CONSTRAINT) return;
    stack->s[stack->top] = *value;
    ++stack->top;
}

void
stackPop(struct stack *stack, char *popped)
{
    *popped = 0;
    if (stack->top <= 0) return;
    --stack->top;
    *popped = stack->s[stack->top];
}

bool
isValid(char* s)
{
    struct stack *st;
    st = calloc(1, sizeof *st);

    for(int i = 0; s[i] != '\0'; ++i) {
        char opener;
        switch (s[i]) {
            case ')':
                stackPop(st, &opener);
                if (opener != '(') return false;
                break;
            case ']':
                stackPop(st, &opener);
                if (opener != '[') return false;
                break;
            case '}':
                stackPop(st, &opener);
                if (opener != '{') return false;
                break;
            default:
                stackPush(st, &s[i]);
        }
    }

    if (st->top > 0) {
        free(st);
        return false;
    }

    free(st);
    return true;
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
