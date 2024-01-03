/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if(left == right)
        return head;

    struct ListNode *left_bound = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *right_bound = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = head;

    struct ListNode *cur = dummy;
    int index = 0;
    while(cur)
    {
        if(index + 1 == left)
            left_bound = cur;
        
        if(index == right)
            right_bound = cur;

        cur = cur->next;
        ++index;
    }

    cur = left_bound->next;
    struct ListNode *next = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *prev = right_bound->next;
    int count = 0;
    while(cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;

        if(count == right - left)
            break;

        ++count;
    }

    left_bound->next = prev;

    return dummy->next;
}