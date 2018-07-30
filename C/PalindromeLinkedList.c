// Easy Collection
// Bloomberg
// Linked List
/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
 */

 /**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     struct ListNode *next;
  * };
  */
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

 struct ListNode* copyList(struct ListNode* head) {
     if (head == NULL) {
         return NULL;
     }
     struct ListNode *p1, *p2, *p, *ret;
     p1 = head;
     p = (struct ListNode*)malloc(sizeof(struct ListNode));
     p2 = ret = p;
     while (p1->next != NULL) {
         p2->val = p1->val;
         p1 = p1->next;
         p = (struct ListNode*)malloc(sizeof(struct ListNode));
         p2->next = p;
         p2 = p2->next;
     }
     p2->val = p1->val;
     p2->next = NULL;
     return ret;
 }

 bool isPalindrome(struct ListNode* head) {
     if (head == NULL) {
         return true;
     }
     struct ListNode* origin = copyList(head);
     struct ListNode* reversed = reverseList(head);
     while (origin != NULL && reversed != NULL) {
         if (origin->val != reversed->val) {
             return false;
         }
         origin = origin->next;
         reversed = reversed->next;
     }
     return true;
 }
