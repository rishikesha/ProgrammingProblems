#include<iostream>
#include<queue>
#include<vector>
#include<sstream>
#include<string>

using namespace std;

class MedianTracker {
    priority_queue<int, vector<int>, greater<int>> p2;
    priority_queue<int> p1;
    public:
    void addItem(int item) {
        if (p1.size() and item > p1.top()) {
            p2.push(item);
        } else {
            p1.push(item);
        }
        if (p1.size() > p2.size() + 1) {
            p2.push(p1.top());
            p1.pop();
        }
        if (p2.size() > p1.size() + 1) {
            p1.push(p2.top());
            p2.pop();
        }
        
    }

    int getMedian() {
        if (p1.size() > p2.size()) {
            return p1.top();
        } else if (p2.size() > p1.size()) {
            return p2.top();
        } else {
            return (p1.top() + p2.top())/2;
        }
    }
};


int main() {
    MedianTracker m;
    istringstream iss;
    string s;
    int n;
    while(true) {
        getline(cin, s);
        if (s.length() == 0)
            break;
        iss = istringstream(s);
        iss >> n;
        m.addItem(n);
        cout << m.getMedian() << endl;
    }
}
