
// 090825
/*
    Circular Queue Using Arrays.
*/

#include <iostream>
using namespace std;

const int INF = 1e9;

class CirQue {
private:
    int * q;
    int front, back;
    int currSize, maxSize;

public:
    CirQue(int size=5);   ~CirQue();
    bool enqueue(int x); 
    bool dequeue();

    int getFront() const;
    int getBack() const;
    int size() const;

    bool isEmpty() const;
    bool isFull() const;
};

CirQue :: CirQue(int size) 
: maxSize(size), currSize(0), front(-1), back(-1) {
    q = new int[maxSize];
}

CirQue :: ~CirQue() {
    delete[] q;
}

bool CirQue :: enqueue(int x) {
    if(isFull()) return false;

    if(front == -1) front = 0;
    back = (back+1) % maxSize;
    q[back] = x;
    currSize++;
    return true;
}

bool CirQue :: dequeue() {
    if(isEmpty()) return false;

    if(front == back) {
        front = back = -1;
    }
    else {      
        front = (front+1) % maxSize;
    }
    currSize--;
    return true;
}

int CirQue :: getFront() const {
    return (isEmpty()) ? INF : q[front];
}
int CirQue :: getBack() const {
    return (isEmpty()) ? INF : q[back];
}
int CirQue :: size() const {
    return currSize;
}

bool CirQue :: isFull() const {
    return ((back+1)%maxSize == front);
}
bool CirQue :: isEmpty() const {
    return (front == -1);
    // return (currSize == 0);
}

int main() {
    int queSize = 3;
    CirQue q(queSize);
    cout << "Created a circular queue of size " << queSize << ".\n";

    int inputEle;
    for(int i = 0; i < 3; i++) {
        inputEle = (i + 1) * 10;
        if(!q.enqueue(inputEle)) {
            cout << "Queue Overflow at enqueue of " << inputEle << "\n";
        } else {
            cout << "Enqueued " << inputEle << " successfully!\n";
        }
    }

    // Attempt to overfill
    inputEle = 40;
    if (!q.enqueue(inputEle)) {
        cout << "Queue Overflow at enqueue of " << inputEle << "\n";
    }

    cout << "\nFront: " << q.getFront() << endl;
    cout << "Back: " << q.getBack() << endl;

    // Perform one dequeue
    q.dequeue();
    cout << "\nAfter one dequeue...\n";
    cout << "Front: " << q.getFront() << endl;
    cout << "Back: " << q.getBack() << endl;

    // Now enqueue again — should succeed in circular queue
    inputEle = 50;
    if (!q.enqueue(inputEle)) {
        cout << "Queue Overflow at enqueue of " << inputEle << "\n";
    } else {
        cout << "Enqueued " << inputEle << " successfully (proving circular behavior).\n";
    }

    // Final state
    cout << "\nFinal queue state:\n";
    cout << "Front: " << q.getFront() << endl;
    cout << "Back: " << q.getBack() << endl;
    cout << "Size: " << q.size() << endl;

    return 0;
}
