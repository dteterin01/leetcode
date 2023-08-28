#include <string>

//
// Created by Danil on 28.08.2023.
//[""visit","visit","visit","back","back","forward","visit","forward","back","back"]
//[["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]
//[null,null,null,null,"facebook.com","google.com","facebook.com",null,"linkedin.com","google.com","leetcode.com"]
class BrowserHistory {
private:
    struct HistoryNode {
        std::string val;

        HistoryNode* next;
        HistoryNode* prev;

        explicit HistoryNode(const std::string &val)
            : val(val), next(nullptr), prev(nullptr)
            {}
    };

    HistoryNode* cur;

public:
    BrowserHistory(const std::string& homepage)
    {
        cur = new HistoryNode(homepage);
    }

    void visit(const std::string& url)
    {
        HistoryNode* allocated_node = new HistoryNode(url);

        cur->next = allocated_node;
        allocated_node->prev = cur;

        cur = allocated_node;
    }

    std::string back(int steps)
    {
        while (steps-- > 0 && cur->prev != nullptr)
        {
            cur = cur->prev;
        }
        return cur->val;
    }

    std::string forward(int steps)
    {
        while (steps-- > 0 && cur->next != nullptr)
        {
            cur = cur->next;
        }
        return cur->val;
    }
};
