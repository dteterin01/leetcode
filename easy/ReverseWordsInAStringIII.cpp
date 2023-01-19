#include <string>

//
// Created by Danil on 20.01.2023.
//
class Solution {
private:
    void reverseHelper(std::string& str, int left, int right) {
        while (left != right) {
            std::swap(str[left], str[right]);
            left++;
            right--;
        }
    }

public:
    std::string reverseWords(std::string s) {
        int right = 0;
        for (int i = 0; i < s.size(); ++i) {
            right = i;
            while (right + 1 != s.size() && s[right + 1] != ' ') right++;
            reverseHelper(s, i, right);
            i = right + 1;
        }
        return s;
    }
};