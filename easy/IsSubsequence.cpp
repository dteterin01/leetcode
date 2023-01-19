#include <string>

//
// Created by Danil on 20.01.2023.
//
class Solution {
public:
    bool isSubsequence(const std::string& s, const std::string& t) {
        if (s.size() < t.size()) return false;
        if (t.empty()) return true;
        for (int sPtr = 0, tPtr = 0; sPtr < s.size(); ++sPtr)
        {
            if (s[sPtr] == t[tPtr])
            {
                if (++tPtr == t.length()) return true;
            }
        }
        return false;
    }
};