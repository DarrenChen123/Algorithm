/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (!headA || !headB) {
        return NULL;
    }
    int lengthA = 0;
    int lengthB = 0;
    struct ListNode * current = headA;
    while (current) {
        lengthA++;
        current = current->next;
    }
    current = headB;
    while (current) {
        lengthB++;
        current = current->next;
    }
    while (lengthA > lengthB) {
        headA = headA->next;
        lengthA--;
    }
    while (lengthA < lengthB) {
        headB = headB->next;
        lengthB--;
    }
    while (headA) {
        if (headA == headB) {
            return headA;
        } else {
            headA = headA->next;
            headB = headB->next;
        }
    }
    return NULL;
}
