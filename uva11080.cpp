/* Rishikesh
 * UVA 11080 Place the guards
 */
#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<iomanip>
#include<cstdint>
#include<numeric>
#include<stack>
#include<queue>
#include<list>
#include<deque>
#include<bitset>
#include<functional>

using namespace std;

bool isBicolorable(int node, vector<int> &visited,
        vector<vector<int>> &adjlist, int color,
        int &numnodes,
        int &numones) {
    numnodes++; // count number of nodes in the component
    if (color == 1) numones++; // count number of nodes colored 1.
    visited[node] = color;
    int neighcolor = (color == 1 ? 2 : 1);
    bool ans = true;
    for (int n : adjlist[node]) {
        if (visited[n]) {
            if (neighcolor == visited[n])
                continue;
            else
                return false;
        } else {
            if (not (ans = ans and isBicolorable(n, visited, adjlist, neighcolor, numnodes, numones)))
                    break;
        }
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        int v,e;
        cin >> v >> e;

        vector<vector<int>> adjlist(v);
        for(int i = 0; i < e; i++) {
            int f, t;
            cin >> f >> t;
            adjlist[f].push_back(t);
            adjlist[t].push_back(f);
        }

        bool ans = true;
        vector<int> visited(v, 0);
        int nguards = 0;
        for (int i = 0; ans and i < v; i++) {
            if ( not visited[i]) { // This true once per component
                int numnodes = 0, numones = 0;
                ans = ans and isBicolorable(i, visited, adjlist, 1, numnodes, numones);
                // Add minimum number of guards needed for this component
                if (numnodes > 1 and numones > numnodes/2)
                    nguards += (numnodes - numones);
                else
                    nguards += numones;
            }
        }

        if (ans) {
            cout << nguards << endl;
        } else {
            cout << -1 << endl;
        }
    }
}
