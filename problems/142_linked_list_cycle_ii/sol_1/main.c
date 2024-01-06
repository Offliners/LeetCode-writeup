/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if(!head || !head->next)
        return NULL;

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    bool find_cycle = false;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            find_cycle = true;
            break;
        }
    }

    if(!find_cycle)
        return NULL;

    slow = head;
    while(slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}