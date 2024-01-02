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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l1_cur = l1;
        ListNode *l2_cur = l2;
        ListNode *ans = new ListNode();
        ListNode *l3_cur = ans;

        int carry = 0;
        while(l1_cur && l2_cur)
        {
            int sum = l1_cur->val + l2_cur->val + carry;
            
            ListNode *temp = new ListNode(sum % 10);
            l3_cur->next = temp;
            carry = sum / 10;

            l1_cur = l1_cur->next;
            l2_cur = l2_cur->next;
            l3_cur = l3_cur->next;
        }

        while(l1_cur)
        {
            int sum = l1_cur->val + carry;
            
            ListNode *temp = new ListNode(sum % 10);
            l3_cur->next = temp;
            carry = sum / 10;

            l1_cur = l1_cur->next;
            l3_cur = l3_cur->next;
        }

        while(l2_cur)
        {
            int sum = l2_cur->val + carry;
            
            ListNode *temp = new ListNode(sum % 10);
            l3_cur->next = temp;
            carry = sum / 10;

            l2_cur = l2_cur->next;
            l3_cur = l3_cur->next;
        }

        if(carry)
        {
            ListNode *temp = new ListNode(carry);
            l3_cur->next = temp;
        }

        return ans->next;
    }
};