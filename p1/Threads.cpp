#include<thread>
#include<iostream>
#include<vector>
#include<iterator>
#include<mutex>
#include<map>
#include<numeric>

using namespace std;
size_t const reps{10};
size_t const threadCount{3};
int c = 0;
mutex mtx;


void countNum(int threadNum) {
    for (int i = 0; i < reps; i++) {
        unique_lock lock(mtx);
        c++;
        cout << "Thread " << threadNum << " has been called " << i << " times" << endl;
    }
}

int main() {
    vector<thread> threads;
    for (int i = 0; i < threadCount; i++) {
        threads.push_back(thread(countNum, i + 1));
    }
    for (auto &thr : threads) {
        thr.join();
    }
    cout << "\nFinal count is " << c << endl;
    return 0;
}
