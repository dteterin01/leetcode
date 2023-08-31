#include <map>
#include <iostream>

//
// Created by Danil on 31.08.2023.
//

// for example:

// a = Added
// a(0, 11)
// [0 11] => 1
//   1
// a(22, 55)
// [0, 11, 22, 55]
//    1  0    1

class MyCalendarThree {
private:
    std::map<int, int> starts;
    int res;

public:
    MyCalendarThree()
    {
        starts[1e9] = 0, starts[0] = 0;
        res = 0;
    }

    int split(int x)
    {
        auto rbTreeIterator = --starts.upper_bound(x);
        starts[x] = rbTreeIterator->second;
    }

    int book(int startTime, int endTime)
    {
        split(startTime);
        split(endTime);
        for (auto it = starts.find(startTime); it->first < endTime; ++it)
        {
            res = std::max(++(it->second), res);
        }
    }
};
