/* Rishikesh
 * UVA 10004
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

bool isBicolorable(int node, vector<int> &visited, vector<vector<int>> &adjlist, int color) {
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
            if (not (ans = ans and isBicolorable(n, visited, adjlist, neighcolor)))
                    break;
        }
    }
    return ans;
}

int main() {
    int n;
    while (cin >> n, n) {
        int m;
        cin >> m;
        vector<vector<int>> adjlist(n);
        for(int i = 0; i < m; i++) {
            int t1, t2;
            cin >> t1 >> t2;
            adjlist[t1].push_back(t2);
            adjlist[t2].push_back(t1);
        }
        bool ans = true;
        vector<int> visited(n, 0);
        for (int i = 0; ans and i < n; i++) {
            if ( not visited[i])
                ans = ans and isBicolorable(i, visited, adjlist, 1);
        }

        if (ans)
            cout << "BICOLORABLE.\n";
        else
            cout << "NOT BICOLORABLE.\n";
    }
}
