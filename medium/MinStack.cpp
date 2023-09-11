#include <stack>

//
// Created by Danil on 01.09.2023.
//
class MinStack {
private:
    std::stack<std::pair<int, int>> stack;

public:
    MinStack() {

    }

    void push(int val)
    {
        if (stack.empty() || val <= stack.top().second) stack.push({val, val});
        else stack.push({val, stack.top().second});
    }

    void pop()
    {
        stack.pop();
    }

    int top()
    {
        return stack.top().first;
    }

    int getMin()
    {
        return stack.top().second;
    }
};