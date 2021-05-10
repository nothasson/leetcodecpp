class Solution {
public:
    ListNode *reverseListR(ListNode *head) {   //递归版本
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *cur = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return cur;
    }
    ListNode* reverseList(ListNode* head) {   //迭代版本
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
