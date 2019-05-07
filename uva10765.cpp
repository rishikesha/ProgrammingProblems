/* Rishikesh
 * UVA 10765 Doves and Bombs
 */
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
#include<functional>
#include<numeric>

const unsigned NOTVISITED = 0;
using namespace std;

void dfs(int node, int &num, vector<vector<int>> &adjlist,
         vector<int> &dfs_num, vector<int> &dfs_low,
         vector<int> &pigeonval, bool isRoot, int parent) {
    dfs_low[node] = dfs_num[node] = ++num;
    int rootChildren = 0;

    for(unsigned nbr : adjlist[node]) {
        if (dfs_num[nbr] == NOTVISITED) {
            if (isRoot)
                rootChildren++;
            dfs(nbr, num, adjlist, dfs_num, dfs_low, pigeonval, false, node);
            if (not isRoot and dfs_low[nbr] >= dfs_num[node]) {
                pigeonval[node]++;
            }
            dfs_low[node] = min(dfs_low[nbr], dfs_low[node]);

        } else {
            dfs_low[node] = min(dfs_low[node], dfs_num[nbr]);
        }
    }
    if (isRoot)
        pigeonval[node] = rootChildren;
}

int main() {
#ifdef DEBUGUVA
    freopen("test", "r", stdin);
#endif
    unsigned n, m;
    while(cin >> n >> m, n > 0) {
        vector<vector<int>> adjlist(n);
        int t1, t2;
        while (cin >> t1 >> t2, t1 >= 0) {
            adjlist[t1].push_back(t2);
            adjlist[t2].push_back(t1);
        }
        vector<int> dfs_num(n, 0), dfs_low(n, 1e9), pigeonval(n, 1);
        int num = 0;
        for(unsigned node = 0; node < n; node++) {
            if (dfs_num[node] == NOTVISITED) {
                dfs(node, num, adjlist, dfs_num, dfs_low, pigeonval,
                    true, -1);
            }
        }
        vector<pair<int, int>> answer;
        for(unsigned i = 0; i < n; i++)
            answer.emplace_back(pigeonval[i], i);

        sort(answer.begin(), answer.end(),
             [](pair<int, int> f, pair<int, int> s) {
            if (f.first == s.first)
                return f.second < s.second;
            else
                return f.first > s.first;});

        for (unsigned i = 0; i < m; i++) {
            cout << answer[i].second << " " << answer[i].first << "\n";
        }
        cout << "\n";
    }
    return 0;
}
