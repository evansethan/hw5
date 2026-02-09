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

const int reps = 12;
const int threadCount = 5;
const int modulo = 3;
const int k = 5;
Stack<double> s;
int c = 0;
//mutex mtx;

void buildStack(int mod) {
    for (int i = 0; i < reps; i++) {
        //lock_guard<mutex> lock(mtx);
        c++;
        if (c % mod == 0) {
            continue;
            //s.pop(); // commented out to avoid second-order race condition
        }
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
            threads.push_back(jthread(buildStack, modulo));
        }
    }
    cout << "Initial stack (counting to " << reps * threadCount << ", every multiple of " << modulo << " removed):\n";
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
    return 0;
}

