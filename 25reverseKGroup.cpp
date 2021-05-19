class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy;
        ListNode *end = dummy;
        while (end->next != nullptr) {
            for (int i = 0; i < k && end != nullptr; ++i)
                end = end->next;
            if (end == nullptr) break;
            ListNode *start = pre->next;
            ListNode *next = end->next;
            end->next = nullptr;
            pre->next = reverse(start);
            start->next = next;
            pre = start;
            end = pre;
        }
        return dummy->next;
    }

private:
    ListNode *reverse(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *cur = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return cur;
    }
};