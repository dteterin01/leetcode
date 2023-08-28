#include <iostream>

//
// Created by Danil on 28.08.2023.
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
        while (count-- > 0) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head->next = cur;
        return prev;
    }

public:

    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = k;
        ListNode* tmp = head;
        while (tmp != nullptr && count-- > 0)
        {
            tmp = tmp->next;
        }

        if (count <= 0)
        {
            ListNode* reversed = reversedList(head, k);

            head->next = reverseKGroup(tmp, k);
            return reversed;
        }
        return head;
    }
};

int main()
{
    auto i = Solution().reverseKGroup(
            new ListNode(
                    1,
                    new ListNode(2,
                                 new ListNode(3,
                                              new ListNode(4,
                                                           new ListNode(5))))
            ),
            2
    );
    std::cout << "chlen";
}