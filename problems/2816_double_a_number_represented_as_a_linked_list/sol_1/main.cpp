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
    ListNode* doubleIt(ListNode* head) {
        ListNode *cur = head;
        while(cur)
        {
            cur->val *= 2;
            cur = cur->next; 
        }

        ListNode *dummy = new ListNode();
        dummy->next = head;
        cur = dummy;
        int carry = 0;
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
};