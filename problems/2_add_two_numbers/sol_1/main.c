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
    while(l1_cur && l2_cur)
    {
        int sum = l1_cur->val + l2_cur->val + carry;
        struct ListNode *temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val = sum % 10;
        temp->next = NULL;
        l3_cur->next = temp;
        carry = sum / 10;

        l1_cur = l1_cur->next;
        l2_cur = l2_cur->next;
        l3_cur = l3_cur->next;
    }

    while(l1_cur)
    {
        int sum = l1_cur->val + carry;
        struct ListNode *temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val = sum % 10;
        temp->next = NULL;
        l3_cur->next = temp;
        carry = sum / 10;

        l1_cur = l1_cur->next;
        l3_cur = l3_cur->next;
    }

    while(l2_cur)
    {
        int sum = l2_cur->val + carry;
        struct ListNode *temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val = sum % 10;
        temp->next = NULL;
        l3_cur->next = temp;
        carry = sum / 10;

        l2_cur = l2_cur->next;
        l3_cur = l3_cur->next;
    }

    if(carry)
    {
        struct ListNode *temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val = carry;
        temp->next = NULL;
        l3_cur->next = temp;
    }

    return ans->next;
}