
// 100825
/*
    Queue from Single STK.
        - * Ver1: Push= O(1) but Pop() and Top() = O(N). [Recursion]
        - Ver2: Push= O(N) and Pop() & Top() => O(1).
        O(N) => via recursion.
        
*/

#include <iostream>
#include <stack>
using namespace std;

class S_Queue {
private:
    stack<int> s1;

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

// O(N) push:
// void S_Queue :: push(int x) {
//     // BASE CASE: When the last element has been popped .. push in the 'x'.
//     if(s1.empty()) {
//         s1.push(x);
//         return;
//     }

//     int currTop = s1.top();
//     s1.pop();

//     // RECURSION.
//     this->push(x);

//     // BACKTRACKING STEP: re-push the elements.
//     s1.push(currTop);
// }

bool S_Queue :: pop() {
    if(isEmpty()) return false;

    int currTop = s1.top();
    s1.pop();

    // BASE CASE: When the last element has been reached & POPPED.
    if(s1.empty()) {
        return true; // FRONT of queue has been POPPED.
    }

    // RECURSION:
    bool result = this->pop();

    // BACKTRACKING: Re-pushing all elements.
    push(currTop);

    return result;
}

int S_Queue :: getFront() {
    if(isEmpty()) return -1;

    int currTop = s1.top();
    s1.pop();

    // BASE CASE: When the last element has been reached.
    if(s1.empty()) { 
        s1.push(currTop);   // Pushing back into the stack.
        return currTop; 
    }

    int frontEle = this->getFront();
    s1.push(currTop);               // BACKTRACKING.
    return frontEle;
}

bool S_Queue :: isEmpty() {
    return s1.empty();
}

void S_Queue :: clear() {
    stack<int>().swap(s1);
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