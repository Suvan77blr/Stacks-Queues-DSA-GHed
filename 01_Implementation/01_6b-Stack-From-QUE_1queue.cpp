
// 100825
/* 
    Stack From QUEUEs  => using a single Queue.
        - PUSH(x) {
            Add to Q.
            for( i: 1->n-1 ) {
                Q.PUSH(Q.FRONT());
                Q.POP();
            }
        }

        - POP(), TOP(), EMPTY() => all remain the same.
*/

#include <iostream>
#include <queue>
using namespace std;

class Q_Stk {
    queue<int> q1;

public:
    Q_Stk();    ~Q_Stk();
    
    void push(int x);       // MAIN CHANGE.
    bool pop();
    int top() const;
    bool empty() const;
    void clear();
};

Q_Stk :: Q_Stk() {}

Q_Stk :: ~Q_Stk() {
    clear();
}

// CHANGE IS HERE ONLY,
void Q_Stk :: push(int x) {
    q1.push(x);
    for(int i=1; i<q1.size(); i++) {
        q1.push(q1.front());
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

// Default main.
int main() {
    Q_Stk stk;

    stk.push(10);
    stk.push(20);
    stk.push(30);

    cout << "Top: "<< stk.top() << endl; // 30
    cout << "Popping .. \n";
    stk.pop();
    cout << "Top: "<< stk.top() << endl; // 20
    cout << "Popping .. \n";
    stk.pop();
    cout << "Top: "<< stk.top() << endl; // 10
    cout << "Popping .. \n";
    stk.pop();
    cout << "Empty? : " << stk.empty() << endl; // 1

    return 0;
}
