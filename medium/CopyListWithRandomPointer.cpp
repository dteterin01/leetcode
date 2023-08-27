
#include <map>
#include <iostream>

//
// Created by Danil on 26.08.2023.
//

class Solution {
private:
    class Node {
    public:
        int val;

        Node* next;
        Node* random;

        Node(int _val) {
            val = _val;
            next = nullptr;
            random = nullptr;
        }
    };

    static void print(std::map<Node*, Node*> map) {
        for (auto & nodes: map) {
            std::cout << nodes.first->val << " " << nodes.second->val << "\n";
        }
    }
public:

    Node* copyRandomList(Node* head) {
        Node * dummy = new Node(0);
        Node * currentPtr = dummy;

        Node * tmpPtr;
        std::map<Node*, Node*> map;

        Node* cycle = head;
        while (cycle != nullptr) {
            tmpPtr = new Node(cycle->val);
            currentPtr->next = tmpPtr;
            currentPtr = currentPtr->next;
            map[cycle] = tmpPtr;

            cycle = cycle->next;
        }

        print(map);
        cycle = head;
        while (cycle != nullptr) {
            if (cycle->random != nullptr) {
                std::cout << "random" << cycle->val << "\n";
                map[cycle]->random = map[cycle->random];
            }

            cycle = cycle->next;
        }
        Node *res = dummy->next;
        delete dummy;
        return res;
    }
};

int main() {
    Solution solution;
};

