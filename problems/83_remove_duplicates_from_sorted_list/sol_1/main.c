/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(!head)
        return NULL;

    struct ListNode* cur = head;
    while(cur && cur->next)
    {
        if(cur->val == cur->next->val)
            cur->next = cur->next->next;
        else
            cur = cur->next;
    }

    return head;
}