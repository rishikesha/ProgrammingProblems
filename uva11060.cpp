/* Rishikesh
 * UVA 11060 Beverages
 * Note that this cannot be done without priority queue.
 */
#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cstdint>
#include<numeric>
#include<stack>
#include<queue>
#include<list>
#include<deque>
#include<bitset>
#include<functional>

using namespace std;

int main() {
    string str;
    int caseno = 0;
    istringstream iss;
    while(getline(cin, str), str.length()) {
        caseno++;
        int N = stoi(str);
        map<string, int> bevToInd; // These two maps are there
        map<int, string> indToBev; // only to translate the problem to ints
        for (int i = 0; i < N; i++) {
            getline(cin, str);
            bevToInd[str] = i;
            indToBev[i] = str;
        }

        int M;
        getline(cin, str);
        M = stoi(str);
        vector<vector<int>> adjlist(N);
        for (int i = 0; i < M; i++) {
            string s1, s2;
            getline(cin, str);
            iss = istringstream(str);
            iss >> s1 >> s2;
            int i1= bevToInd[s1];
            int i2= bevToInd[s2];
            adjlist[i1].push_back(i2);
        }

        vector<int> indegree(N, 0);

        for(auto vs : adjlist) {
            for (int i : vs) {
                indegree[i]++;
            }
        }

        vector<int> answer;
        priority_queue<int, vector<int>, greater<int>> inqueue;
        for (int i = 0; i < N; i++) {
            if (indegree[i] == 0) {
                inqueue.push(i);
            }
        }

        while (inqueue.size()) {
            int t = inqueue.top();
            inqueue.pop();
            answer.push_back(t);
            for(int v : adjlist[t]) {
                indegree[v]--;
                if (indegree[v] == 0)
                    inqueue.push(v);
            }
        }

        cout << "Case #" << caseno << ": Dilbert should drink beverages in this order:";
        for (auto it = answer.begin(); it != answer.end(); it++) {
            cout << " " << indToBev[*it];
        }
        cout << ".\n\n";
        getline(cin, str);
    }
}

