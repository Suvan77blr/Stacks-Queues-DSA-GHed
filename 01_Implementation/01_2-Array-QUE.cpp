
// 080825.
/*
    Queue Imple., using Arrays.
*/

#include <iostream>
using namespace std;

const int INF = 1e9;

class Que_Arr {
public:
    Que_Arr(int size=5);    
    ~Que_Arr();

    bool enqueue(int val);
    bool dequeue();

    int getFront() const;
    int getBack() const;
    int size() const;
    bool isEmpty() const;
    bool isFull() const;

private:
    int front, back;
    int * que;
    int maxSize, currSize;
};

Que_Arr :: Que_Arr(int size) {
    maxSize = size;
    currSize = 0;
    que = new int[size];
    front = -1; back = -1;
}

Que_Arr :: ~Que_Arr() {
    delete[] que;
}

bool Que_Arr :: enqueue(int val) {
    if(isFull()) {
        return false;   // enqueue failure.
    }
    if(front == -1) front = 0;  // For the first element.
    back += 1;
    que[back] = val;
    currSize++;
    return true;        // enqueue success.
}

bool Que_Arr :: dequeue() {
    if(isEmpty()) {
        cout << "Queue Underflow!!\n";
        return false;   // dequeue failure.
    }
    front++;
    currSize--;

    if(front > back) {
        // Resetting queue back to the reset state.
        front = back = -1;
    }
    return true;
}

int Que_Arr :: getFront() const {
    return (isEmpty()) ? INF : que[front];
}

int Que_Arr :: getBack() const {
    return (isEmpty()) ? INF : que[back];
}

int Que_Arr :: size() const {
    return currSize;
} 

bool Que_Arr :: isEmpty() const {
    return (currSize == 0);
}

bool Que_Arr :: isFull() const {
    return (currSize == maxSize || back == maxSize-1);
}

int main() {
    int queSize = 3;
    Que_Arr q(queSize);
    cout << "Created a queue of " << queSize << " elements.\n";
    int inputEle;
    for(int i=0; i<4; i++) {
        inputEle = (i+1)*10;
        if(!q.enqueue(inputEle)) {
            cout << "Queue Overflow at enqueue of " << inputEle << "\n";
        } 
        else {
            cout << "Enqueued " << inputEle << " successfully!\n";
        }
    }

    cout << "Front: " << q.getFront() << endl;
    cout << "Back: " << q.getBack() << endl;
    q.dequeue();
    cout << "Front after dequeue: " << q.getFront() << endl;
    cout << "Back after dequeue: " << q.getBack() << endl;
    cout << "Size: " << q.size() << endl;

    // Trying to enqueue new element after a single DEQUEUE.
    cout << "Demonstrating linear queue flaw! ..  (after dequeue, even if currSize < maxSize)\n";
    inputEle = 50;
    if (!q.enqueue(inputEle)) {
        cout << "Queue Overflow at enqueue of " << inputEle << "\n";
    } else {
        cout << "Enqueued " << inputEle << " successfully!\n";
    }

    // Print current queue status
    cout << "Final queue front: " << q.getFront() << endl;
    cout << "Final queue back: " << q.getBack() << endl;
    cout << "Final queue size: " << q.size() << endl;



    return 0;
}
