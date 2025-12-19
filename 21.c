#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *
mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    if (list1 == NULL && list2 == NULL) return NULL;
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    struct ListNode *result, *head;

    for (result = NULL;;) {
        if (result == NULL) {
            if (list1->val <= list2->val) {
                result = list1;
                list1 = list1->next;
            } else {
                result = list2;
                list2 = list2->next;
            }

            head = result;
        } else {
            if (list1->val <= list2->val) {
                result->next = list1;
                result = result->next;
                list1 = list1->next;
            } else {
                result->next = list2;
                result = result->next;
                list2 = list2->next;
            }
        }

        if (list1 == NULL) {
            if (list2 != NULL) result->next = list2;
            break;
        }

        if (list2 == NULL) {
            if (list1 != NULL) result->next = list1;
            break;
        }
    }

    return head;
}

void
freeLinkedList(struct ListNode *list)
{
    if (list == NULL) return;
    freeLinkedList(list->next);
    free(list);
}

int
main(void)
{
    struct ListNode *list1, *list2;

    list1 = calloc(1, sizeof *list1);
    assert(list1);
    list1->val = 1;
    list1->next = calloc(1, sizeof *list1);
    assert(list1->next);
    list1->next->val = 2;
    list1->next->next = calloc(1, sizeof *list1);
    assert(list1->next->next);
    list1->next->next->val = 4;

    list2 = calloc(1, sizeof *list2);
    assert(list2);
    list2->val = 1;
    list2->next = calloc(1, sizeof *list2);
    assert(list2->next);
    list2->next->val = 3;
    list2->next->next = calloc(1, sizeof *list2);
    assert(list2->next->next);
    list2->next->next->val = 4;

    struct ListNode *result, *head;
    result = mergeTwoLists(list1, list2);
    head = result;

    while (result != NULL) {
        printf("(%d)", result->val);
        if (result->next == NULL) {
            printf("\n");
            break;
        } else {
            printf(" -> ");
            result = result->next;
        }
    }

    freeLinkedList(head);

    return 0;
}
