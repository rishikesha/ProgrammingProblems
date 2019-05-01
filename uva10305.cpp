/* Rishikesh
 * UVA 10305 Ordering Tasks
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

void dfs(int node, vector<vector<int>> &adjlist, vector<int> &visited, vector<int> &exitorder){
    visited[node] = true;
    for(int nxt : adjlist[node]) {
        if (not visited[nxt]) {
            dfs(nxt, adjlist, visited, exitorder);
        }
    }
    exitorder.push_back(node);
}

int main() {
    int n,m;
    while(cin >> n >> m, n) {
        vector<vector<int>> adjlist(n);
        vector<int> visited(n, 0);
        vector<int> exitorder;
        for(int i = 0; i < m; i++) {
            int t1, t2;
            cin >> t1 >> t2;
            adjlist[--t1].push_back(--t2);
        }

        for(int i = 0; i < n; i++) {
            if (not visited[i]) {
                dfs(i, adjlist, visited, exitorder);
            }
        }
        cout << ++exitorder[n - 1];
        for(int i = n - 2; i >= 0; i--)
            cout << " " << ++exitorder[i];
        cout << "\n";
    }
}
