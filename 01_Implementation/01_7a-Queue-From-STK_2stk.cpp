
// 100825
/*
    Queue from STKs.
        PUSH(x) {
            Add to s1.              // OTHER: s1->s2; add to s1; s2->s1. => O(N).
        }

        POP() {
            if(s2 is NOT empty()) 
            {   s2.pop()  }
            else {
                All s1 -> s2.
                s2.pop()
            }
        }
        ... same for TOP().

        EMPTY() { return s1.empty() && s2.empty(); }
*/

#include <iostream>
#include <stack>
using namespace std;

class S_Queue {
private:
stack<int> s1, s2;

public:
    S_Queue() {}    ~S_Queue();
    void push(int x);
    bool pop();
    int getFront();
    bool isEmpty();
    void clear();
};

S_Queue :: ~S_Queue() {
    clear();
}

void S_Queue :: push(int x) {
    s1.push(x);
}

bool S_Queue :: pop() {
    if(isEmpty()) return false;

    if(!s2.empty()) {   
        s2.pop();    
    }

    else {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        // int temp = s2.top();
        s2.pop();
    }
    return true;
}

int S_Queue :: getFront() {
    if(isEmpty()) return -1;

    if(!s2.empty()) {   return s2.top();    }

    else {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        return s2.top();
    }
}

bool S_Queue :: isEmpty() {
    return s1.empty() && s2.empty();
}

void S_Queue :: clear() {
    stack<int>().swap(s1);
    stack<int>().swap(s2);
}

int main() {
    S_Queue q;
    int pushEle;

    pushEle = 10;
    q.push(pushEle);
    cout << "Pushed " << pushEle << " into S_QUEUE!\n";
    pushEle = 20;
    q.push(pushEle);
    cout << "Pushed " << pushEle << " into S_QUEUE!\n";
    pushEle = 30;
    q.push(pushEle);
    cout << "Pushed " << pushEle << " into S_QUEUE!\n";

    cout << "Front: " << q.getFront() << endl; // 10
    cout << "Popping .. \n";
    q.pop();
    cout << "Front: " << q.getFront() << endl; // 20
    cout << "Popping .. \n";
    q.pop();
    cout << "Front: " << q.getFront() << endl; // 30
    cout << "Popping .. \n";
    q.pop();
    cout << "Empty? : " << q.isEmpty() << endl; // 1

    return 0;
}

/*
void Another_PUSH(int x) {
    while(!s1.empty()) {
        s2.push(s1.front());
        s1.pop();
    }
    
    s1.push(x);
    
    while(!s2.empty()) {
        s1.push(s2.front());
        s2.pop();
    }
} => O(2N) for every PUSH.
*/