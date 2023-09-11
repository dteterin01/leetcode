#include <vector>
#include <unordered_map>
#include <unordered_set>

//
// Created by Danil on 01.09.2023.
//
class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board)
    {
        std::vector<short> row(9, 0), col(9, 0), grid(9, 0);
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] == '.') continue;
                int idx = 1 << (board[i][j] - '0');
                if (row[i] & idx || col[j] & idx || grid[i/3 * 3 + j/3] & idx)
                    return false;
                row[i] |= idx;
                col[j] |= idx;
                grid[i/3 * 3 + j/3] |= idx;
            }
        }

        return true;
    }
};