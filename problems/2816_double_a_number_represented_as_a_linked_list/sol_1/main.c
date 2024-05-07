/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* doubleIt(struct ListNode* head){
    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = head;
    struct ListNode *cur = dummy;

    while(cur)
    {
        cur->val *= 2;
        cur = cur->next;
    }

    int carry = 0;
    cur = dummy;
    while(cur && cur->next)
    {
        carry = cur->next->val / 10;
        cur->next->val %= 10;
        cur->val += carry;
        cur = cur->next;
    }

    if(dummy->val)
        return dummy;
    else
        return dummy->next;
}