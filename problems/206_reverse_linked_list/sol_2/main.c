/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(!head || !head->next)
        return head;

    struct ListNode *root = reverseList(head->next);

    head->next->next = head;
    head->next = NULL;

    return root;
}