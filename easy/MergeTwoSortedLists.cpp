#include <climits>

//
// Created by Danil on 26.08.2023.
//
class Solution {
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

public:

    //list1 = [1,2,4], list2 = [1,3,4,5]
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        if (list1->val > list2->val)
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
        else
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
    }
};