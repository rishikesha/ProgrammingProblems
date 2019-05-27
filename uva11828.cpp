/* Rishikesh
 * UVA  11838 Come and Go
 * This program uses Tarjan's SCC algorithm. We do not have to compute the
 * strongly connected components, so there is no stack. Instead
 * there is variable nComponents which keeps track of number of\
 * components seen in one dfs run starting at node 1 (0 in the code below).
 * At the end I check if all the nodes are reachable from node 1 (0 in the
 * code below), and only one strongly connected component has been seen.
 */
#include<iostream>
#include<string>
#include<sstream>
#include<map>
#include<set>
#include<stack>
#include<vector>
#include<algorithm>
#include<functional>
#include<numeric>

using namespace std;

void tarjan(int node,
            vector<vector<int>> &adjlist,
            vector<int> &dlow,
            vector<int> &dnum,
            int &num,
            int &nComponents) {
    dlow[node] = dnum[node] = (++num);
    for(int n : adjlist[node]) {
        if (not dnum[n]) {
            tarjan(n, adjlist, dlow, dnum, num, nComponents);
        }
        dlow[node] = min(dlow[node], dlow[n]);
    }
    if (dlow[node] == dnum[node])
        nComponents++;
}


int main() {
#ifdef DEBUGUVA
    freopen("test", "r", stdin);
    cout << "This is a DEBUG\n";
#endif
    string str;
    int n, m;
    while (cin >> n >> m, n > 0) {
        vector<vector<int>> adjlist(n);
        for (int i = 0; i < m; i++) {
            int t1, t2, t3;
            cin >> t1 >> t2 >> t3;
            adjlist[--t1].push_back(--t2);
            if (t3 > 1) {
                adjlist[t2].push_back(t1);
            }
        }
        vector<int> dlow(n, 0), dnum(n, 0);
        int num = 0, nComponents = 0;
        tarjan(0, adjlist, dlow, dnum, num, nComponents);
        cout << (all_of(dlow.begin(), dlow.end(), [](int i) { return i != 0;})
             and nComponents == 1) << endl;
    }
}
