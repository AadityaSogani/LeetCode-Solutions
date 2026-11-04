
#include <iostream>
#include <deque>
using namespace std;

class FrontMiddleBackQueue {
private:
    deque<int> left, right;

    // Balance both halves
    void balance() {
        if (left.size() > right.size()) {
            right.push_front(left.back());
            left.pop_back();
        }
        else if (right.size() > left.size() + 1) {
            left.push_back(right.front());
            right.pop_front();
        }
    }

public:

    // Constructor
    FrontMiddleBackQueue() {
    }

    // Insert at front
    void pushFront(int val) {
        left.push_front(val);
        balance();
    }

    // Insert at middle
    void pushMiddle(int val) {
        if (left.size() < right.size()) {
            left.push_back(val);
        }
        else {
            right.push_front(val);
        }
        balance();
    }

    // Insert at back
    void pushBack(int val) {
        right.push_back(val);
        balance();
    }

    // Remove from front
    int popFront() {
        if (left.empty() && right.empty()) {
            return -1;
        }

        int ans;

        if (!left.empty()) {
            ans = left.front();
            left.pop_front();
        }
        else {
            ans = right.front();
            right.pop_front();
        }

        balance();
        return ans;
    }

    // Remove from middle
    int popMiddle() {
        if (left.empty() && right.empty()) {
            return -1;
        }

        int ans;

        if (left.size() == right.size()) {
            ans = left.back();
            left.pop_back();
        }
        else {
            ans = right.front();
            right.pop_front();
        }

        balance();
        return ans;
    }

    // Remove from back
    int popBack() {
        if (left.empty() && right.empty()) {
            return -1;
        }

        int ans;

        if (!right.empty()) {
            ans = right.back();
            right.pop_back();
        }
        else {
            ans = left.back();
            left.pop_back();
        }

        balance();
        return ans;
    }
};

// Main function
int main() {

    FrontMiddleBackQueue q;

    cout << "Push Front 1" << endl;
    q.pushFront(1);

    cout << "Push Back 2" << endl;
    q.pushBack(2);

    cout << "Push Middle 3" << endl;
    q.pushMiddle(3);

    cout << "Push Middle 4" << endl;
    q.pushMiddle(4);

    cout << "Pop Front: " << q.popFront() << endl;
    cout << "Pop Middle: " << q.popMiddle() << endl;
    cout << "Pop Middle: " << q.popMiddle() << endl;
    cout << "Pop Back: " << q.popBack() << endl;
    cout << "Pop Front: " << q.popFront() << endl;

    return 0;
}
