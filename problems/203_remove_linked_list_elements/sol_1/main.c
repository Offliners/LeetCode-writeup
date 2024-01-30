/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    if(!head)
        return NULL;

    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = head;

    struct ListNode* cur = dummy;
    while(cur && cur->next)
    {
        struct ListNode* temp = cur->next;
        while(temp && temp->val == val)
            temp = temp->next;
        
        cur->next = temp;
        cur = cur->next;
    }

    return dummy->next;
}