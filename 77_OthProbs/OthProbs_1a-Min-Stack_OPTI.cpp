
// 110825.
/*
    Min-Stack.
        - To implement a stack w/ getMin() operation to fetch the current min. ele.
*/

#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> stk;
    int minEle;

public:
    MinStack();
    ~MinStack();

    void push(int x);
    bool pop();
    int top();
    int getMin();
};

MinStack :: MinStack()
    : minEle(1e9) {}


MinStack :: ~MinStack() {
    stack<int>.swap(stk);
}

void MinStack :: push(int x) {
    if(stk.empty()) {   
        stk.push(x);    
    }
    else {
        if(x > minEle) {
            stk.push(x);
        }
        else {
            stk.push(2LL * x - minEle);
            minEle = x;
        }
    }
}

void MinStack :: pop() {
    if(stk.empty()) return;
    int topEle = stk.top();
    stk.pop();

    if(topEle < minEle) {
        minEle = 2LL * minEle - topEle;
    }
}

int MinStack :: top() {
    if(stk.empty()) return -1;

    int topEle = stk.top();

    return (topEle < minEle) ? minEle : topEle; 
}

int MinStack :: getMin() {
    return minEle;
}