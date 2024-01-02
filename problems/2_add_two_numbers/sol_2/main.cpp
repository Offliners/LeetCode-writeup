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
        ListNode* l1_cur = l1;
        ListNode* l2_cur = l2;
        ListNode* ans = new ListNode();
        ListNode* l3_cur = ans;
        
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

            ListNode* temp = new ListNode(value % 10);
            l3_cur->next = temp;
            l3_cur = l3_cur->next;
            carry = value / 10;
        }

        return ans->next;
    }
};