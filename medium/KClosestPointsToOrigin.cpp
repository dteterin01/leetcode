#include <vector>
#include <valarray>
#include <queue>

//
// Created by Danil on 26.08.2023.
//
class Solution {

private:

    struct Info {
        int x;
        int y;
        double distance;
        Info(int x, int y) : x(x), y(y) {
            distance = std::sqrt(x * x + y * y);
        }

        int operator[] (int i) const {
            if (i == 0) {
                return x;
            }
            if (i == 1) {
                return y;
            }
            return 0;
        }
    };

    class Comparator {
    public:
        bool operator() (Info point1, Info point2) {
            if (point1.distance > point2.distance)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    };

public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {
        std::priority_queue<Info, std::vector<Info>, Comparator> queue;
        for (auto & point : points) {
            queue.push(Info(point[0], point[1]));
        }

        std::vector<std::vector<int>> result;
        for (int i = 0; i < k; ++i) {
            Info point = queue.top();
            result.push_back(std::vector{point[0], point[1]});
            queue.pop();
        }
        return result;
    }
};