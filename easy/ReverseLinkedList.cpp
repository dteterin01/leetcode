//
// Created by Danil on 28.08.2023.
//
class Solution {
private:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    // 1->2->3->4->5
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (cur != nullptr)
        {
            ListNode* next = cur->next;
            cur->next = prev;

            prev = cur;
            cur = prev;
        }

        return prev;
    }
};