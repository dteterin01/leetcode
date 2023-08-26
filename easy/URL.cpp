#include <string>
#include <iostream>

//
// Created by Danil on 30.01.2023.
//
class Solution {
public:
    std::string ReplaceSpaces(std::string& S, std::size_t length) {
        std::size_t size = length - 1;
        for (const auto& i : S) {
            if (i == ' ') {
                size += 2;
            }
        }

        std::size_t curPos = size;
        for (std::size_t i = S.length() - 1; i < UINT32_MAX; i--) {
            if (S[i] == ' ') {
                S[curPos--] = '0';
                S[curPos--] = '2';
                S[curPos--] = '%';
            } else {
                S[curPos--] = S[i];
            }
        }
        return S;
    }
};

int main() {
    std::string test = "test test f f";
    test.resize(100);

    Solution solution;
    std::cout << solution.ReplaceSpaces(test, test.length());
}