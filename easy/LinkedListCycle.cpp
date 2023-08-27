//
// Created by Danil on 26.08.2023.
//


#include <cstdlib>
#include <set>
#include <list>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//
// 3 2 0 4
// 3 -> 2 -> 2 -> 4 -> 2...
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution().hasCycle(new ListNode(1));
}
