
#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue {
private:
    vector<int> arr;
    int front;
    int rear;
    int size;
    int count;

public:

    // Constructor
    MyCircularQueue(int k) {
        arr.resize(k);
        front = 0;
        rear = -1;
        size = k;
        count = 0;
    }

    // Insert element into queue
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        rear = (rear + 1) % size;
        arr[rear] = value;
        count++;

        return true;
    }

    // Delete element from queue
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        front = (front + 1) % size;
        count--;

        return true;
    }

    // Get front element
    int Front() {
        if (isEmpty()) {
            return -1;
        }

        return arr[front];
    }

    // Get rear element
    int Rear() {
        if (isEmpty()) {
            return -1;
        }

        return arr[rear];
    }

    // Check if queue is empty
    bool isEmpty() {
        return count == 0;
    }

    // Check if queue is full
    bool isFull() {
        return count == size;
    }
};

// Main function
int main() {

    MyCircularQueue q(3);

    cout << boolalpha;

    cout << "Enqueue 1: " << q.enQueue(1) << endl;
    cout << "Enqueue 2: " << q.enQueue(2) << endl;
    cout << "Enqueue 3: " << q.enQueue(3) << endl;
    cout << "Enqueue 4: " << q.enQueue(4) << endl;

    cout << "Rear: " << q.Rear() << endl;

    cout << "Is Full: " << q.isFull() << endl;

    cout << "Dequeue: " << q.deQueue() << endl;

    cout << "Enqueue 4: " << q.enQueue(4) << endl;

    cout << "Rear: " << q.Rear() << endl;

    cout << "Front: " << q.Front() << endl;

    cout << "Is Empty: " << q.isEmpty() << endl;

    return 0;
}
