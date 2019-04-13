#include<iostream>
#include<stack>
#include<vector>

using namespace std;

bool checkPossible(vector<int>& v) {
    stack<int> s;
    int j = 0;
    for (int i =1; i <= v.size(); i++) {
        s.push(i);
        while (not s.empty() and s.top() == v[j]) {
            j++;
            s.pop();
        }
    }

    return s.size() == 0;
}


int main() {
    int n;
    while (cin >> n, n >0) {
        int m;
        while (cin >> m, m > 0) {
            vector<int> v; v.push_back(m);
            for (int i = 1; i< n; i++) {
                cin >> m;
                v.push_back(m);
            }

            if (checkPossible(v)) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
        cout << "\n";
    }
}
