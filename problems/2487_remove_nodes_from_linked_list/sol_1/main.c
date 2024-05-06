/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNodes(struct ListNode* head) {
    if(!head)
        return NULL;

    struct ListNode *node = head;
    struct ListNode *next = removeNodes(node->next);

    node->next = next;
    if(!next || node->val >= next->val)
        return node;
    
    return next;
}