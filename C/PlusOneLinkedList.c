// Subscription
// Bloomberg
/*
Given a non-negative integer represented as non-empty a singly linked list of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.

Example:
Input:
1->2->3

Output:
1->2->4
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int plus(struct ListNode* head) {
    if (!head) {
        return 0;
    }
    head->val = head->val + (head->next ? plus(head->next) : 1);

    if (head->val >= 10) {
        head->val %= 10;
        return 1;
    } else {
        return 0;
    }
}

struct ListNode* plusOne(struct ListNode* head) {
    if (!head) {
        return head;
    }
    if (plus(head) == 0) {
        return head;
    } else {
        struct ListNode* newHead = (struct ListNode*) malloc (sizeof(struct ListNode));
        newHead->val = 1;
        newHead->next = head;
        return newHead;
    }
}
