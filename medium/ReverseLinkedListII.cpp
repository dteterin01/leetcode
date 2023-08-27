#include <algorithm>
#include <iostream>

//
// Created by Danil on 26.08.2023.
//

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode* reversedList(ListNode* head, int count) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (count-- >= 0) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head->next = cur;
        return prev;
    }

    ListNode* shift(ListNode* head, int shiftSize) {
        while (head != nullptr && shiftSize > 0) {
            head = head->next;
            shiftSize--;
        }
        return head;
    }

public:

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        ListNode* dummy = new ListNode(0, head);
        ListNode* leftNodeBefore = shift(dummy, left - 1);
        leftNodeBefore->next = reversedList(leftNodeBefore->next, right - left);
        return dummy->next;
    }
};

int main() {
    auto i = Solution().reverseBetween(
            new ListNode(
                    1,
                    new ListNode(2,
                                 new ListNode(3,
                                              new ListNode(4,
                                                           new ListNode(5))))
                    ),
                    2,
                    4
            );

    std::cout << i->val;
};
