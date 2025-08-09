
// 090825
/*
    Stack Using LL.
*/
#include <iostream>
using namespace std;

const int INT_MIN = -1;

class LLStk {
private:
    class Node {        // Node is private to LLStk.
    public:
        int data; Node* next;
        Node(int data, Node* next=nullptr) 
            : data(data), next(next) {}
    };
    
    Node* topNode;
    int currSize;

public:
    LLStk();
    ~LLStk();
    void push(int x);
    bool pop();
    int top() const;
    bool empty() const;
    int size() const;
    void clear();   
};

LLStk :: LLStk() {
    topNode = nullptr;
    currSize = 0;
}

LLStk :: ~LLStk () {
    clear();
}

void LLStk :: push(int val) {
    Node* newNode = new Node(val);
    newNode->next = topNode;
    topNode = newNode;
    currSize++;
}

bool LLStk :: pop() {
    if(empty()) return false;

    Node* temp = topNode;
    topNode = topNode->next;
    delete temp;
    currSize--;
    return true;
}

int LLStk :: top() const {
    if(empty()) return INT_MIN;
    return topNode->data;
}

bool LLStk :: empty() const {
    return (topNode==nullptr);
}

int LLStk :: size() const {
    return currSize;
}

void LLStk :: clear() {
    Node* temp;
    while(topNode) {
        temp = topNode;
        topNode = topNode->next;
        delete temp;
    }
    currSize = 0;
}