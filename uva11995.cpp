#include<stack>
#include<queue>
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main() {
    string ss;
    istringstream iss;
    while (getline(cin, ss), ss.length()) {
        int op, item, n;
        bool imp, q, s, pq;
        imp = q = s = pq = true;
        stack<int> st;
        queue<int> qu;
        priority_queue<int> prq;


        iss  = istringstream(ss);
        iss >> n;
        for(int i = 0; i < n; i++) {
            getline(cin, ss);
            iss = istringstream(ss);
            iss >> op >> item;
            if (op == 1) {
                qu.push(item);
                st.push(item);
                prq.push(item);
            } else {
                q = q  and  not qu.empty() and (qu.front() == item);
                s = s and not st.empty() and (st.top() == item);
                pq = pq and not prq.empty() and (prq.top() == item);
                if(not qu.empty()) qu.pop();
                if(not st.empty()) st.pop();
                if(not prq.empty()) prq.pop();
            }
        }

        if (q and not s and not pq){
            printf("queue\n");
        } else if (not q and s and not pq) {
            printf("stack\n");
        } else if (not q and not s and pq) {
            printf("priority queue\n");
        } else if (not q and not s and not pq) {
            printf("impossible\n");
        } else {
            printf("not sure\n");
        }
    }
}
