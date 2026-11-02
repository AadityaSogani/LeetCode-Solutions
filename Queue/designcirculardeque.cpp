
#include <iostream>
#include <vector>
using namespace std;

class MyCircularDeque {
private:
    vector<int> arr;
    int front;
    int rear;
    int size;
    int count;

public:

    // Constructor
    MyCircularDeque(int k) {
        arr.resize(k);
        front = 0;
        rear = -1;
        size = k;
        count = 0;
    }

    // Insert element at front
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }

        if (isEmpty()) {
            front = 0;
            rear = 0;
        }
        else {
            front = (front - 1 + size) % size;
        }

        arr[front] = value;
        count++;

        return true;
    }

    // Insert element at rear
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }

        if (isEmpty()) {
            front = 0;
            rear = 0;
        }
        else {
            rear = (rear + 1) % size;
        }

        arr[rear] = value;
        count++;

        return true;
    }

    // Delete element from front
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }

        if (count == 1) {
            front = 0;
            rear = -1;
        }
        else {
            front = (front + 1) % size;
        }

        count--;

        return true;
    }

    // Delete element from rear
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }

        if (count == 1) {
            front = 0;
            rear = -1;
        }
        else {
            rear = (rear - 1 + size) % size;
        }

        count--;

        return true;
    }

    // Get front element
    int getFront() {
        if (isEmpty()) {
            return -1;
        }

        return arr[front];
    }

    // Get rear element
    int getRear() {
        if (isEmpty()) {
            return -1;
        }

        return arr[rear];
    }

    // Check if deque is empty
    bool isEmpty() {
        return count == 0;
    }

    // Check if deque is full
    bool isFull() {
        return count == size;
    }
};

// Main function
int main() {

    MyCircularDeque dq(3);

    cout << boolalpha;

    cout << "Insert Last 1: "
         << dq.insertLast(1) << endl;

    cout << "Insert Last 2: "
         << dq.insertLast(2) << endl;

    cout << "Insert Front 3: "
         << dq.insertFront(3) << endl;

    cout << "Insert Front 4: "
         << dq.insertFront(4) << endl;

    cout << "Get Rear: "
         << dq.getRear() << endl;

    cout << "Is Full: "
         << dq.isFull() << endl;

    cout << "Delete Last: "
         << dq.deleteLast() << endl;

    cout << "Insert Front 4: "
         << dq.insertFront(4) << endl;

    cout << "Get Front: "
         << dq.getFront() << endl;

    return 0;
}
