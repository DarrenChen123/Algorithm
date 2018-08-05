// Easy Collection
// Bloomberg
// Microsoft
// Facebook
// Linked List
// Amazon
/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/

bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }
    struct ListNode *slow = head->next;
    struct ListNode *fast = head->next->next;
    while (slow != NULL && fast != NULL) {
        if (slow == fast) {
            return true;
        } else {
            slow = slow->next;
            if (fast->next) {
                fast = fast->next->next;
            } else {
                return false;
            }
        }
    }
    return false;
}
