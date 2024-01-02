/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *l1_cur = l1;
    struct ListNode *l2_cur = l2;
    struct ListNode *ans = (struct ListNode*)malloc(sizeof(struct ListNode));
    ans->val = 0;
    ans->next = NULL;
    struct ListNode *l3_cur = ans;

    int carry = 0;
    while(l1_cur || l2_cur || carry)
    {
        int value = carry;

        if(l1_cur)
        {
            value += l1_cur->val;
            l1_cur = l1_cur->next;
        }

        if(l2_cur)
        {
            value += l2_cur->val;
            l2_cur = l2_cur->next;
        }

        struct ListNode *temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val = value % 10;
        temp->next = NULL;
        l3_cur->next = temp;
        carry = value / 10;
        l3_cur = l3_cur->next;
    }

    return ans->next;
}