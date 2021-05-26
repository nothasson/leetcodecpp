class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        int len1 = 0;
        int len2 = 0;
        while(p1 != nullptr){
            len1++;
            p1 = p1->next;
        }
        while(p2 != nullptr){
            len2++;
            p2 = p2->next;
        }
        ListNode *slow = headB;
        ListNode *fast = headA;
        int minus = len1 - len2;
        if(len1 < len2){
            slow = headA;
            fast = headB;
            minus = len2 - len1;
        }
        while(minus-- != 0 ){
            fast = fast->next;
        }
        while(fast!=nullptr && fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};