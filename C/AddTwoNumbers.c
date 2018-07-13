// Medium Collection
// Bloomberg
// Amazon
// Microsoft
// Facebook
/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }
    struct ListNode* current = (struct ListNode*) malloc (sizeof(struct ListNode));
    current->val = (l1->val + l2->val) % 10;
    int flag = (l1->val + l2->val) / 10;
    current->next = NULL;
    struct ListNode* ret = current;
    l1 = l1->next;
    l2 = l2->next;
    while (l1 != NULL || l2 != NULL) {
        struct ListNode* new = (struct ListNode*) malloc (sizeof(struct ListNode));
        new->val = ((l1 ?  l1->val : 0) + (l2 ? l2->val : 0) + flag) % 10;
        new->next = NULL;
        flag = ((l1 ? l1->val : 0) + (l2 ? l2->val : 0) + flag) / 10;
        current->next = new;
        current = current->next;
        if (l1) {
            l1 = l1->next;
        }
        if (l2) {
            l2 = l2->next;
        }
    }
    if (flag) {
        struct ListNode* new = (struct ListNode*) malloc (sizeof(struct ListNode));
        new->val = 1;
        new->next = NULL;
        current->next = new;
        current = current->next;
    }
    return ret;
}
