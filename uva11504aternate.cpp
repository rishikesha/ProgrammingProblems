/* Rishikesh
 * UVA  11504 Dominoes
 * Do DFS twice. In the first DFS record,
 * record the finishing time, and reverse sort
 * the nodes according to finishing times.
 * (Below I append to the vector named sorted
 * the end of each visit to a node, and eventually reverse this vector)
 * This would be topological sort algorithm if our
 * graph was a DAG.
 * In the second DFS, use this order restart dfs each time dfs
 * has to be restarted when there are still nodes to be explored.
 * The number of restarts gives the number of dominoes which have
 * to be pushed. Each restart is equivalent to giving a nudge to
 * a domino.
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

void topSort(int node, vector<vector<int>> &adjlist, vector<int> &visited,
             vector<int> &sorted) {
    visited[node] = true;
    for(int neigh : adjlist[node]) {
        if (not visited[neigh]) {
            topSort(neigh, adjlist, visited, sorted);
        }
    }
    sorted.push_back(node);
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
        for(int i = 0; i < m; i++) {
            int t1, t2;
            cin >> t1 >> t2;
            adjlist[--t1].push_back(--t2);
        }

        vector<int> sorted, visited(n, 0), dummy;
        for (int i = 0; i < n; i++) {
            if(not visited[i]) {
                topSort(i, adjlist, visited, sorted);
            }
        }
        int answer = 0;
        visited.clear();
        visited.resize(n , 0);
        reverse(sorted.begin(), sorted.end());
        for (int i : sorted) {
            if (not visited[i]) {
                answer++;
                topSort(i, adjlist, visited, dummy);
            }
        }
        cout << answer << endl;
    }
}
