// Easy Collection
// Microsoft
// Yelp
// Facebook
// Linked List
// Amazon
// LinkedIn
/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }
    struct ListNode* ret = (struct ListNode*) malloc (sizeof(struct ListNode));
    if (l1->val <= l2->val) {
        ret->val = l1->val;
        l1 = l1->next;
    } else {
        ret->val = l2->val;
        l2 = l2->next;
    }
    ret->next = NULL;
    struct ListNode* current = ret;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val <= l2->val) {
            struct ListNode* new = (struct ListNode*) malloc (sizeof(struct ListNode));
            new->val = l1->val;
            new->next = NULL;
            current->next = new;
            current = current->next;
            l1 = l1->next;
        } else {
            struct ListNode* new = (struct ListNode*) malloc (sizeof(struct ListNode));
            new->val = l2->val;
            new->next = NULL;
            current->next = new;
            current = current->next;
            l2 = l2->next;
        }
    }
    if (l1 == NULL) {
        while (l2 != NULL) {
            struct ListNode* new = (struct ListNode*) malloc (sizeof(struct ListNode));
            new->val = l2->val;
            new->next = NULL;
            current->next = new;
            current = current->next;
            l2 = l2->next;
        }
    }
    if (l2 == NULL) {
        while (l1 != NULL) {
            struct ListNode* new = (struct ListNode*) malloc (sizeof(struct ListNode));
            new->val = l1->val;
            new->next = NULL;
            current->next = new;
            current = current->next;
            l1 = l1->next;
        }
    }
    return ret;
}
