#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include <ctime>

struct ClockGenerator {
    clock_t operator()() const {
        return clock();
    }
};

// int main() {
//     std::list<clock_t> clockList;
//
//     std::generate_n(std::back_inserter(clockList), 10, ClockGenerator());
//
//     clockList.sort();
//     clockList.unique();
//
//     std::cout << "Унікальні значення clock():" << std::endl;
//     std::copy(clockList.begin(), clockList.end(),
//               std::ostream_iterator<clock_t>(std::cout, "\n"));
//
//     return 0;
// }
