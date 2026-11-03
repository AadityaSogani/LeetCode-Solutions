
#include <iostream>
#include <queue>
using namespace std;

class RecentCounter {
private:
    queue<int> requests;

public:
    RecentCounter() {
    }

    int ping(int t) {

        requests.push(t);

        while (!requests.empty() && requests.front() < t - 3000) {
            requests.pop();
        }

        return requests.size();
    }
};

int main() {

    RecentCounter recentCounter;

    cout << "Ping(1): " << recentCounter.ping(1) << endl;
    cout << "Ping(100): " << recentCounter.ping(100) << endl;
    cout << "Ping(3001): " << recentCounter.ping(3001) << endl;
    cout << "Ping(3002): " << recentCounter.ping(3002) << endl;

    return 0;
}
