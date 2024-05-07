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
        int carry = helper(cur);

        if(carry)
        {
            ListNode *dummy = new ListNode();
            dummy->val = carry;
            dummy->next = head;
            return dummy;
        }
        else
            return head;
    }

    int helper(ListNode* node)
    {
        if(!node)
            return 0;
        
        int value = node->val * 2 + helper(node->next);
        node->val = value % 10;

        return value / 10;
    }
};