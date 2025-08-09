
// 090825
/*
    Queue Using LL.
*/
#include <iostream>
using namespace std;

const int INF = -1;

class LLQue {
private:
    class Node {
    public:
        int data; Node* next;

        Node(int data, Node* next=nullptr) 
            : data(data), next(next) { }
    };

    Node *front, *back;
    int currSize;

public:
    LLQue();                ~LLQue();
    void push(int x);       bool pop();
    int getFront() const;   int getBack() const;
    bool isEmpty() const;     int getSize() const;
    void clear();
};

LLQue :: LLQue() {
    front = back = nullptr;
    currSize = 0;
}

LLQue :: ~LLQue () {
    clear();
}

void LLQue :: push(int val) {
    Node* newNode = new Node(val);
    if(back == nullptr) {
        front = back = newNode;
    }
    else {
        back->next = newNode;
        back = back->next;
    }
    currSize++;
}

bool LLQue :: pop() {
    if(empty()) return false;

    Node* temp = front;
    front = front->next;
    delete temp;
    currSize--;

    if(front == nullptr) { front = back = nullptr; }
    return true;
}

int LLQue :: getFront() const {
    return (isEmpty()) ? INF : front->data;
}
int LLQue :: getBack() const {
    return (isEmpty()) ? INF : back->data;
}
int LLQue :: getSize() const {
    return currSize;
}

bool LLQue :: isEmpty() const {
    return (front == nullptr);
}

void LLQue :: clear() {
    Node* temp;
    while(front) {
        temp = front;
        front = front->next;
        delete temp;
    }
    front = back = nullptr;
    currSize = 0;
}