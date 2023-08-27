//
// Created by Danil on 26.08.2023.
//

#include <iostream>

class Solution {
private:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        int extra = 0;

        int l1Value, l2Value, sum;
        ListNode* tmp;
        while (l1 != nullptr || l2 != nullptr) {
            l1Value = 0; l2Value = 0;
            if (l1 != nullptr) {
                l1Value = l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                l2Value = l2->val;
                l2 = l2->next;
            }

            sum = l1Value + l2Value + extra;
            sum %= 10;
            extra = sum / 10;
            tmp = new ListNode(sum);
            cur->next = tmp;
            cur = cur->next;
            std::cout << sum << " ";
        }

        if (extra != 0) {
            cur->next = new ListNode(1);
        }

        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};