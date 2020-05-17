# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        evenHead = even = ListNode(None)
        oddHead = odd = ListNode(None)
        
        while head:
            odd.next = head
            odd = odd.next
            even.next = head.next
            even = even.next
            head = head.next.next if even else None
        
        odd.next = evenHead.next
        
        return oddHead.next
