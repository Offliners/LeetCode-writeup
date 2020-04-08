# Day 8 - Middle of the Linked List
Given a non-empty, singly linked list with head node head, return a middle node of linked list.

If there are two middle nodes, return the second middle node.

#### Example 1
```
Input: [1,2,3,4,5]
Output: Node 3 from this list (Serialization: [3,4,5])
The returned node has value 3.  (The judge's serialization of this node is [3,4,5]).
Note that we returned a ListNode object ans, such that:
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and ans.next.next.next = NULL.
```

#### Example 2
```
Input: [1,2,3,4,5,6]
Output: Node 4 from this list (Serialization: [4,5,6])
Since the list has two middle nodes with values 3 and 4, we return the second one.
```

### C
```C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    return slow;
}
```
[code](C/Middle-of-the-Linked-List.c)

#### Result
```
Runtime: 0 ms, faster than 100.00% of C online submissions for Middle of the Linked List.
Memory Usage: 5.3 MB, less than 100.00% of C online submissions for Middle of the Linked List.
```

### Python
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        slow, fast = head, head
        
        while fast and fast.next:
            slow, fast = slow.next, fast.next.next
            
        return slow
```
[code](Python/Middle-of-the-Linked-List.py)

#### Result
```
Runtime: 24 ms, faster than 86.36% of Python3 online submissions for Middle of the Linked List.
Memory Usage: 14 MB, less than 7.14% of Python3 online submissions for Middle of the Linked List.
```
