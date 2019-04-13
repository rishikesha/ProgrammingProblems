/* Rishikesh
 * UVA 1062
 */

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>

using namespace std;

int getNumStacks(string& contType) {
    vector<stack<char>> st;
    for(auto c : contType) {
        size_t i = 0;
        bool failed = true;
        for(;i < st.size(); i++) {
            if (st[i].top() >= c) {
                st[i].push(c);
                failed = false;
                break;
            }
        }
        if (failed) {
            stack<char> t; t.push(c);
            st.push_back(t);
        }
    }
    return st.size();
}


int main() {
    int i = 1;
    string s;
    while(cin >> s, s != "end") {
        cout << "Case " << i << ": " << getNumStacks(s) << endl;
        i++;
    }
}
