#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *
addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *result = calloc(1, sizeof *result);
    assert(result);

    struct ListNode *resultHead = result;

    int carry = 0;
    for (int val1, val2, sum;;) {
        val1 = l1 == NULL ? 0 : l1->val;
        val2 = l2 == NULL ? 0 : l2->val;

        sum = val1 + val2 + carry;
        carry = 0;
        if (sum > 9) {
            sum -= 10;
            carry = 1;
        }

        result->val = sum;
        result->next = NULL;

        if ((l1 != NULL && l1->next != NULL) || (l2 != NULL && l2->next != NULL)) {
            result->next = calloc(1, sizeof *result->next);
            assert(result->next);
            result = result->next;
            if (l1 != NULL) l1 = l1->next;
            if (l2 != NULL) l2 = l2->next;
        } else {
            if (carry > 0) {
                result->next = calloc(1, sizeof *result->next);
                assert(result->next);
                result = result->next;
                result->val = carry;
                result->next = NULL;
            }

            break;
        }
    }

    return resultHead;
}

void
freeListNode(struct ListNode *head)
{
    if (head == NULL) return;
    freeListNode(head->next);
    free(head);
}

int
main(void)
{
    struct ListNode *l1, *l2;
    l1 = calloc(1, sizeof *l1);
    assert(l1);
    l2 = calloc(1, sizeof *l2);
    assert(l2);

    l1->val = 2;
    l1->next = calloc(1, sizeof *l1->next);
    assert(l1->next);
    l1->next->val = 4;
    l1->next->next = calloc(1, sizeof *l1->next->next);
    assert(l1->next->next);
    l1->next->next->val = 3;

    l2->val = 5;
    l2->next = calloc(1, sizeof *l2->next);
    assert(l2->next);
    l2->next->val = 6;
    l2->next->next = calloc(1, sizeof *l2->next->next);
    assert(l2->next->next);
    l2->next->next->val = 4;

    struct ListNode *result, *resHead;
    result = addTwoNumbers(l1, l2);
    resHead = result;

    printf("[");
    while (result != NULL) {
        printf("%d,", result->val);
        result = result->next;
    }
    printf("\b]\n");

    freeListNode(l1);
    freeListNode(l2);
    freeListNode(resHead);

    return 0;
}
