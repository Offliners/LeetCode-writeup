/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return nullptr;

        ListNode *next = nullptr;
        ListNode *prev = nullptr;
        ListNode *cur = head;

        while(cur)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        } 

        return prev;
    }
};