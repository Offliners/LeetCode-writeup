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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next)
            return head;

        ListNode *cur = head;
        while(cur && cur->next)
        {
            int a = cur->val;
            int b = cur->next->val;
            ListNode *gcd_node = new ListNode(gcd(a, b));
            gcd_node->next = cur->next;
            cur->next = gcd_node;
            cur = cur->next->next;
        }

        return head;
    }

    int gcd(int a, int b)
    {
        if(a % b == 0)
            return b;
        
        return gcd(b, a % b);
    }
};