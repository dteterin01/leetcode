#include <string>
#include <vector>
#include <stack>

//
// Created by Danil on 01.09.2023.
//
class Solution {
private:
    template<class Fn>
    void eval(std::stack<int64_t>& st, Fn fn)
    {
        int64_t f = st.top(); st.pop();
        int64_t s = st.top(); st.pop();

        st.push(fn(f, s));
    }
public:
    int64_t evalRPN(std::vector<std::string>& tokens)
    {
        std::stack<int64_t> numbers;
        for (const auto& token: tokens)
        {
            if (token == "+") eval(numbers, [](int64_t f, int64_t s) { return f + s; });
            else if (token == "-") eval(numbers, [](int64_t f, int64_t s) { return f - s; });
            else if (token == "*") eval(numbers, [](int64_t f, int64_t s) { return f * s; });
            else if (token == "/") eval(numbers, [](int64_t f, int64_t s) { return f / s; });
            else numbers.push(std::stoi(token));
        }
        return numbers.top();
    }
};