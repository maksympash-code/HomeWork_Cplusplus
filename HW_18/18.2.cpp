#include <iostream>
#include <stack>

namespace my {
    template<class T>
    struct Node {
        T item;
        Node<T>* next;
    };

    // template<class T>;

}
// int main() {
//     std::stack<int> std_stack;
//
//     for (int i = 1 ; i < 6; i++)
//         std_stack.push(i);
//
//     while (!std_stack.empty()) {
//         std::cout << std_stack.top() << ' ';
//         std_stack.pop();
//     }
//     std::cout << std::endl;
//
//     return 0;
// }