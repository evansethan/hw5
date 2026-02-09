#include"Stack.h"
#include<iostream>


using namespace mpcs;

int main(){
    Stack<double> s;
    s.push(6.5);
    s.push(2.3);
    s.push(100);
    s.push(9);
    std::cout << "stack: ";
    s.print();
    std::cout << "pop: " << s.pop() << std::endl;
    std::cout << "pop: " << s.pop() << std::endl;
    std::cout << "stack: ";
    s.print();
    std::cout << "pop: " << s.pop() << std::endl;
    std::cout << "pop: " << s.pop() << std::endl;
    std::cout << "stack: ";
    s.print();
}
