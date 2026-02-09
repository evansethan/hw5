#ifndef STACK_H
#define STACK_H

#include <vector>
#include <iostream>
#include <initializer_list>

namespace mpcs {

template <typename T>
class Stack{
private:
    std::vector<T> s;
public:
Stack(std::initializer_list<T> list = {}) : s(list) {
    std::cout << "new ";
    print();
}
void print() {
    std::cout << "stack: ";
    for (T& elem : s) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}
void push(T t) {
    s.push_back(t);
}
T pop() {
    if (s.empty()) {
        throw std::runtime_error("List is empty");
    }
    T t = s.back();
    s.pop_back();
    return t;
}
};
}
#endif