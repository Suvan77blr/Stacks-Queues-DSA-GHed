
// 110825.
/*
    Min-Stack.
        - To implement a stack w/ getMin() operation to fetch the current min. ele.
*/

#include <iostream>
#include <stack>
using namespace std;
using pii = pair<int, int>;

class MinStack {
private:
    stack<pii> stk;

public:
    MinStack();
    ~MinStack();

    void push(int x);
    bool pop();
    int top();
    int getMin();
};

MinStack :: MinStack() {}

MinStack :: ~MinStack() {
    stack<pii>().swap(stk);
}

void MinStack :: push(int x) {
    if(stk.empty()) {
        stk.push({x, x});
    }
    else {
        stk.push({x, min(stk.top().second, x)});
    }
}

void MinStack :: pop() {
    if(stk.empty()) return;
    stk.pop();
}

int MinStack :: top() {
    return stk.top().first;
}

int MinStack :: getMin() {
    return stk.top().second;
}