class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *p = dummy;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        p->next = l1 != nullptr ? l1 : l2;
        return dummy->next;
    }
};