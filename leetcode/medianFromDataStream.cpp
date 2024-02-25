#include <queue>
using namespace std;

class MedianFinder {
public:
    priority_queue<int> less;
    priority_queue<int, vector<int>, greater<int>> greaterQ;

    MedianFinder() {}
void addNum(int num) {
    less.push(num);

    if (!greaterQ.empty() && less.top() > greaterQ.top()) {
        int val1 = less.top();
        less.pop();
        int val2 = greaterQ.top();
        greaterQ.pop();
        less.push(val2);
        greaterQ.push(val1);
    }
    if (less.size() > greaterQ.size() + 1) {
        int val = less.top();
        less.pop();
        greaterQ.push(val);
    } else if (greaterQ.size() > less.size()) {
        int val = greaterQ.top();
        greaterQ.pop();
        less.push(val);
    }
}


    double findMedian() {
        if (less.size() > greaterQ.size()) {
            return less.top();
        }
        if (greaterQ.size() > less.size()) {
            return greaterQ.top();
        } else {
            return (less.top() + greaterQ.top()) / 2.0;
        }
    }
};