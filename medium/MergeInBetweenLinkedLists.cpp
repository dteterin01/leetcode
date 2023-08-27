//
// Created by Danil on 26.08.2023.
//

#include <memory>

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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2)
    {
        auto t1 = list1;
        for (int i = 0; i < a - 1; ++i)
        {
            t1 = t1->next;
        }

        auto t2 = list1;
        for (int i = 0; i < b; ++i)
        {
            t2 = t2->next;
        }

        auto nextAfterList2 = t2->next;
        t1->next = list2;

        auto t3 = list2;
        while (t3->next != nullptr)
        {
            t3 = t3->next;
        }

        t3->next = nextAfterList2;
        return list1;
    }
};