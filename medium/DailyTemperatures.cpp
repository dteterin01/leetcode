#include <vector>
#include <stack>
#include <cassert>

//
// Created by Danil on 26.08.2023.
//
class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures)
    {
        std::stack<int> stack;
        stack.push(0);

        int size = temperatures.size();
        std::vector<int> result (size, 0);
        for (int i = 1; i < size; ++i)
        {
            if (!stack.empty() && temperatures[stack.top()] < temperatures[i])
            {
                while (!stack.empty() && temperatures[stack.top()] < temperatures[i] ){
                    result[stack.top()] = i - stack.top();
                    stack.pop();
                }
            }
            stack.push(i);
        }
        return result;
    }
};

int main() {
    std::vector<int> a {73,74,75,71,69,72,76,73};
    Solution solution;
    auto b = solution.dailyTemperatures(a);

    std::vector<int> res {1,1,4,2,1,1,0,0};
};
