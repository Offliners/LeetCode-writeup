/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){
    
    struct ListNode* start = malloc(sizeof(struct ListNode));
    struct ListNode *odd = start, *evenHead = start, *even = head;
    
    start->next = head;
    bool isOdd = true;
    
    while (even != NULL) {
        if (isOdd && odd->next != even)
        {
            evenHead->next = even->next;
            even->next = odd->next;
            odd->next = even;
            even = evenHead->next;
            odd = odd->next;
        } 
        else 
        {
            odd = isOdd ? odd->next : odd;
            evenHead = even;
            even = even->next;
        }
        
        isOdd = !isOdd;
    }
    
    return start->next;
}
