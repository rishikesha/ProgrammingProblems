/* Rishikesh
 * UVA 796 Critical Links
 */
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

#define UNVISITED 0
#define ROOT true
#define NOTROOT false

void dfs(int node,
         int &num,
         vector<vector<int>> &adjlist,
         vector<int> &dfs_low,
         vector<int> &dfs_num,
         bool isRoot,
         int parent,
         vector<pair<int, int>> &critical_links) {
    dfs_low[node] = dfs_num[node] = ++num;
    int rootChildren = 0;

    for (int nbr : adjlist[node]) {
        if (dfs_num[nbr] == UNVISITED) {
            if(isRoot)
                rootChildren++;

            dfs(nbr, num, adjlist, dfs_low, dfs_num, NOTROOT, node, critical_links);

            if (dfs_low[nbr] > dfs_num[node])
                critical_links.emplace_back(node, nbr);
            dfs_low[node] = min(dfs_low[node], dfs_low[nbr]);
        } else if (nbr != parent) {
            dfs_low[node] = min(dfs_low[node], dfs_num[nbr]);
        }
    }
}

int main() {
#ifdef DEBUGUVA
    freopen("test", "r", stdin);
#endif

    string str;
    getline(cin, str);
    int nservers = stoi(str);
    while(true) {
        vector<vector<int>> adjlist(nservers);
        for(int i = 0; i < nservers; i++) {
            getline(cin, str);
            istringstream iss(str);
            string str1, str2;
            int t1, t2;
            iss >> t1;
            iss >> str1;
            str2 = str1.substr(1,str1.length() - 2);
            int n = stoi(str2);
            for (int i = 0; i < n; i++) {
                iss >> t2;
                adjlist[t1].push_back(t2);
            }
        }

        int num = 0;
        vector<int> dfs_low(nservers, 1e9), dfs_num(nservers, 0);
        vector<pair<int, int>> critical_links;
        for(int i = 0; i < nservers; i++)
        dfs(i, num, adjlist, dfs_low, dfs_num, ROOT, -1, critical_links);

        cout << critical_links.size() << " critical links\n";
        for(int i = 0; i < critical_links.size(); i++) {
            if (critical_links[i].first > critical_links[i].second)
                swap(critical_links[i].first, critical_links[i].second);
        }
        sort(critical_links.begin(), critical_links.end());

        for(auto p : critical_links) {
            cout << p.first << " - " << p.second << endl;
        }
        cout << "\n";

        getline(cin, str);
        getline(cin, str);
        if (cin.eof())
            break;
        nservers = stoi(str);
    }
    return 0;
}
