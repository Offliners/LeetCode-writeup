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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return nullptr;

        ListNode *dummy = new ListNode();
        dummy->next = head;

        ListNode *cur = dummy;
        while(cur && cur->next)
        {
            ListNode *temp = cur->next;
            while(temp && temp->val == val)
                temp = temp->next;
            
            cur->next = temp;
            cur = cur->next;
        }

        return dummy->next;
    }
};