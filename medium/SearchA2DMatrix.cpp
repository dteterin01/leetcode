#include <vector>

//
// Created by Danil on 30.08.2023.
//
class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target)
    {
        int row_size = matrix.size(), column_size = matrix[0].size(), l = 0, r = row_size * column_size - 1;

        int mid, tmp_row, tmp_column, tmp;
        while (l <= r)
        {
            mid = (l + r) / 2;
            tmp_row = mid / column_size;
            tmp_column = mid % column_size;
            tmp = matrix[tmp_row][tmp_column];

            if (tmp == target)
            {
                return true;
            }

            if (tmp > target)
            {
                r = mid - 1;
            }
            else
            {
                r = mid + 1;
            }
        }
        return false;
    }
};