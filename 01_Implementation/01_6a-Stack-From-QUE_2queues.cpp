
// 100825
/* 
    Stack From QUEUEs  => using 2 Queues.
        - PUSH(x) {
            Add to Q2.
            while( Q1 is not EMPTY() ) {
                Q2.PUSH(Q1.FRONT());
                Q1.POP();
            }
            SWAP(Q1, Q2);
        }

        - POP(), TOP(), EMPTY(), CLEAR() => all are done via Q1 ONLY.
*/


#include <iostream>
#include <queue>
using namespace std;

class Q_Stk {
    queue<int> q1, q2;

public:
    Q_Stk();    ~Q_Stk();
    
    void push(int x);
    bool pop();
    int top() const;
    bool empty() const;
    void clear();
};

Q_Stk :: Q_Stk() {}

Q_Stk :: ~Q_Stk() {
    clear();
}

void Q_Stk :: push(int x) {
    q2.push(x);
    while(!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
    }
}

bool Q_Stk :: pop() {
    if(empty()) return false;
    // int temp = q1.top();
    q1.pop();
    return true;
}

int Q_Stk :: top () const {
    return empty() ? -1 : q1.front();
}

bool Q_Stk :: empty() const {
    return q1.empty();
}

void Q_Stk :: clear() {
    queue<int>().swap(q1);
}