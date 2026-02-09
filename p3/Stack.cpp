#include"Stack.h"
#include<thread>
#include<iostream>
#include<vector>
#include<iterator>
#include<mutex>
#include<map>
#include<numeric>
using namespace mpcs;
using namespace std;

const int reps = 10;
const int threadCount = 3;
const int k = 5;
Stack<double> s;
int c = 0;

void buildStack() {
    for (int i = 0; i < reps; i++) {
        c++;
        s.push(c);
    }
}

void removeTopK(int threadNum, int k) {
    for (int i = 0; i < k; i++) {
        s.pop();
    }
}

int main() {
    {
        vector<jthread> threads;
        for (int i = 1; i <= threadCount; i++) {
            threads.push_back(jthread(buildStack));
        }
    }
    cout << "Initial stack (counting to " << reps * threadCount << ")" << endl;
    s.print();
    {
        vector<jthread> threads;
        for (int i = 1; i <= threadCount; i++) {
            threads.push_back(jthread(removeTopK, i, k));
        }
    }
    cout << endl;
    cout << "Final stack (top " << k * threadCount << " removed):\n";
    s.print();
    cout << "popped: " << s.pop() << endl;
    return 0;
}

