#include <string>

//
// Created by Danil on 26.08.2023.
//
class Solution {
private:

    static bool isContains(
            std::string& needle,
            std::string& haystack,
            int idx) {
        int needleSize = needle.size();
        int hayStackSize = haystack.size();

        for (int i = idx, j = 0; j < needleSize; ++j, ++i) {

            if (i >= hayStackSize || haystack[i] != needle[j]) {
                return false;
            }
        }
        return true;
    }

public:
    int strStr(std::string haystack, std::string needle) {
        int hayStackSize = haystack.size();
        for (int i = 0; i < hayStackSize; ++i) {
            if (haystack[i] == needle[0] && isContains(needle, haystack, i)) {
                return i;
            }
        }

        return -1;
    }
};

int main() {
    auto res = Solution().strStr("sississip", "issip");
}