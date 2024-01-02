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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right)
            return head;

        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *left_bound = nullptr;
        ListNode *right_bound = nullptr;
        ListNode *temp = dummy;

        int index = 0;
        while(temp)
        {
            if(index + 1 == left)
                left_bound = temp;
            if(index == right)
                right_bound = temp;

            temp = temp->next;
            ++index;
        }

        int count = 0;
        ListNode *cur = left_bound->next;
        ListNode *prev = right_bound->next;
        ListNode *next = nullptr;
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
};