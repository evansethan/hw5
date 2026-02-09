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

const int reps = 15;
const int threadCount = 5;
const int modulo = 3;
const int k = 5;
Stack<double> s;
mutex mtx;
int c = 0;

void buildStack(int mod) {
    scoped_lock lock(mtx);
    for (int i = 0; i < reps; i++) {
        c++;
        s.push(c);
        if (c % mod == 0) {
            s.pop();
        }
    }
}

void removeTopK(int threadNum, int k) {
    scoped_lock lock(mtx);
    cout << "Thread " << threadNum << " removed: (";
    for (int i = 0; i < k; i++) {
        cout << s.pop() << ", ";
    }
    cout << ")" << endl;
}

int main() {
    {
        vector<jthread> threads;
        for (int i = 1; i <= threadCount; i++) {
            threads.push_back(jthread(buildStack, modulo));
        }
    }
    {
        vector<jthread> threads;
        for (int i = 1; i <= threadCount; i++) {
            threads.push_back(jthread(removeTopK, i, k));
        }
    }
    cout << endl;
    cout << "Final stack:\n";
    s.print();
    return 0;
}

