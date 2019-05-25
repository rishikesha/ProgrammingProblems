/* Rishikesh
 * UVA  11504 Dominoes
 * Compute Strongly connected components
 * Get the DAG whose vertices are the strongly
 * connected components and edges are edges
 * between the SCC in original graph.
 * Find the number of SCC which do not have
 * an incoming edge.
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


#define UNVISITED 0

using namespace std;


void tarjanSCC(int node, vector<vector<int>> &adjlist,
         vector<int>& dfs_low, vector<int>& dfs_num,
         stack<int> &scc_stack, int& num,
               vector<int> &components, vector<int> &instack,
               int &currComponent) {
    scc_stack.push(node);
    instack[node] = true;
    dfs_low[node] = dfs_num[node] = ++num;
    for (int neigh : adjlist[node]) {
        if (dfs_num[neigh] == UNVISITED) {
            tarjanSCC(neigh, adjlist, dfs_low, dfs_num, scc_stack,
                      num, components, instack,  currComponent);
        }
        if (dfs_low[neigh] < dfs_low[node] and instack[neigh])
            dfs_low[node] = dfs_low[neigh];
    }
    if (dfs_low[node] == dfs_num[node]) {
        int n;
        do {
            n = scc_stack.top();
            scc_stack.pop();
            instack[n] = false;
            components[n] = currComponent;
        } while( n != node);
        currComponent++;
    }
}

int countOrigins(vector<int> &components, int nComponents,
                 vector<vector<int>> &adjlist) {
    //build reverse DAG of components and find vertices
    //with zero outgoing edges. These vertices corresponds to
    // vertices with zero incoming
    // edges in the component DAG.
    // We do not have to be
    // compute precisely since we want to only identify
    // zero vs. nonzero outgoing edges.
    // There will be zero outgoing edges from i if
    // componentDag[i] = 1, and 0 otherwise.
    vector<int> componentDag(nComponents, 1);
    for(int i = 0 ; i < adjlist.size(); i++) {
        for(int j : adjlist[i]) {
            if (components[i] != components[j]) {
                componentDag[components[j]] = 0;
            }
        }
    }
    return accumulate(componentDag.begin(), componentDag.end(), 0);
}

int main() {
#ifdef DEBUGUVA
    freopen("test", "r", stdin);
    cout << "This is a DEBUG\n";
#endif
    int ncases;
    cin >> ncases;
    while(ncases--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adjlist(n);
        for (int i = 0; i < m ; i++) {
            int from, to;
            cin >> from >> to;
            adjlist[--from].push_back(--to);
        }

        int currComponent = 0, num = 0;
        vector<int> dfs_low(n, 0), dfs_num(n, 0), instack(n, 0),
                components(n, -1);
        stack<int> scc_stack;
        for (int i = 0; i < n; i++) {
            if (dfs_num[i] == UNVISITED) {
                tarjanSCC(i, adjlist, dfs_low, dfs_num, scc_stack, num,
                          components, instack, currComponent);
            }
        }
        cout << countOrigins(components, currComponent,  adjlist) << endl;
    }
}
