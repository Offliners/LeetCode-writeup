/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int gcd(int a, int b)
{
    if(a % b == 0)
        return b;
    
    return gcd(b, a % b);
}

struct ListNode* insertGreatestCommonDivisors(struct ListNode* head){
    if(!head || !head->next)
        return head;

    struct ListNode *cur = (struct ListNode*)malloc(sizeof(struct ListNode));
    cur = head;
    while(cur && cur->next)
    {
        int a = cur->val;
        int b = cur->next->val;
        struct ListNode *gcd_node = (struct ListNode*)malloc(sizeof(struct ListNode));
        gcd_node->val = gcd(a, b);
        gcd_node->next = cur->next;
        cur->next = gcd_node;

        cur = cur->next->next;
    }

    return head;
}