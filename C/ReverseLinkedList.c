// Easy Collection
/*
 Reverse a singly linked list.

 click to show more hints.

Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//Iterative
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }
    struct ListNode* current = head;
    struct ListNode* previous = NULL;
    while (current != NULL) {
        struct ListNode* temp = current->next;
        current->next = previous;
        previous = current;
        current = temp;
    }
    head = previous;
    return head;
}

//Recursive
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        return head;
    }
    struct ListNode* ret = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return ret;
}
