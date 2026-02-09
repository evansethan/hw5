#ifndef STACK_H
#  define STACK_H

#include<vector>
#include<iostream>

namespace mpcs {

template <typename T>
class Stack{
private:
    std::vector<T> s;
    int i;
public:
Stack() {
    i = 3;
}
void print() {
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