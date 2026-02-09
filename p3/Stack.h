#ifndef STACK_H
#define STACK_H

#include <vector>
#include <iostream>
#include <initializer_list>
#include <shared_mutex>
#include <thread>

using namespace std;
namespace mpcs {

template <typename T>
class Stack{
private:
    vector<T> s;
    shared_mutex mtx;
public:
Stack(initializer_list<T> list = {}) : s(list) {
}
void print() {
    shared_lock lock(mtx);
    cout << "<bottom ";
    for (T& elem : s) {
        cout << elem << " ";
    }
    cout << "top>" << "\nnext pop: " << s.back() << endl;
}
void push(T t) {
    unique_lock lock(mtx);
    s.push_back(t);
}
T pop() {
    unique_lock lock(mtx);
    if (s.empty()) {
        throw runtime_error("List is empty");
    }
    T t = s.back();
    s.pop_back();
    return t;
}
};
}
#endif