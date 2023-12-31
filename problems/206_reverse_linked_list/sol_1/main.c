/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(!head)
        return NULL;

    struct ListNode* prev = NULL;
    struct ListNode* next = NULL;
    struct ListNode* cur = head;
    while(cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}