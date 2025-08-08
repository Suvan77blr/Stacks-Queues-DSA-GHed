
// 080825.
/*
    Stack Imple., using Arrays.
*/

#include <iostream>
using namespace std;

const int INF = 1e9;

class Stk_Arr {
public:
    Stk_Arr(int size=5);
    ~Stk_Arr();
    void push(int val);
    void pop();
    int getTop() const;
    int size() const;
    bool isEmpty() const;
    bool isFull() const;

private:
    int top;
    int * stk;
    int maxSize;
};

Stk_Arr :: Stk_Arr(int size) {
    maxSize = size;
    stk = new int[size];
    top = -1;
}

Stk_Arr :: ~Stk_Arr() {
    delete[] stk;
}

void Stk_Arr :: push(int val) {
    if(isFull()) {
        cout << "Stack Overflow!!\n";
        return;
    }
    top += 1;
    stk[top] = val;
}

void Stk_Arr :: pop() {
    if(isEmpty()) {
        cout << "Stack Underflow!!\n";
        return;
    }
    top -= 1;
}

int Stk_Arr :: getTop() const {
    return (isEmpty()) ? INF : stk[top];
}

int Stk_Arr :: size() const {
    return top + 1;
} 

bool Stk_Arr :: isEmpty() const {
    return (top == -1);
}

bool Stk_Arr :: isFull() const {
    return (top+1 == maxSize);
}

int main() {
    Stk_Arr s(3);
    s.push(10); 
    s.push(20);
    s.push(30);
    s.push(40); // Triggers Overflow.

    cout << "Top: " << s.getTop() << endl;
    s.pop();
    cout << "Top after pop: " << s.getTop() << endl;
    cout << "Size: " << s.size() << endl;

    s.pop();
    s.pop();
    s.pop(); // Triggers Underflow

    return 0;
}
