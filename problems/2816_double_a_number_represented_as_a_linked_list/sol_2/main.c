/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int helper(struct ListNode *node)
{
    if(!node)
        return 0;
    
    int value = node->val * 2 + helper(node->next);
    node->val = value % 10;

    return value / 10;
}

struct ListNode* doubleIt(struct ListNode* head){
    struct ListNode *cur = head;
    int carry = helper(cur);

    if(carry)
    {
        struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
        dummy->val = carry;
        dummy->next = head;
        return dummy;
    }
    else
        return head;
}