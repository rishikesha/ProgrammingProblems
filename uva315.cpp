/* Rishikesh
 * UVA 315 Network
 */
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<numeric>

#define UNVISITED 0
#define ROOT 1

using namespace std;



/*void dfs(int node, vector<vector<int>> &adjlist,
         int &num, vector<int> &dfs_low, vector<int> &dfs_num,
         vector<int> &answer, bool isRoot, int parent)*/

void dfs(int node,
         vector<vector<int>> &adjlist,
         int &num,
         vector<int> &dfs_low,
         vector<int> &dfs_num,
         vector<int> &answer,
         bool isRoot,
         int parent) {
    dfs_low[node] = dfs_num[node] = ++num;

    int rootChildren = 0;

    for (int nbr : adjlist[node]) {
        if (dfs_num[nbr] == UNVISITED) {
            dfs(nbr, adjlist, num, dfs_low, dfs_num, answer, false, node);
            if (isRoot)
                rootChildren++;
            dfs_low[node] = min(dfs_low[nbr], dfs_low[node]);
            if (not isRoot and dfs_low[nbr] >= dfs_num[node])
                answer[node] = 1;
        } else if (nbr != parent) {
            dfs_low[node] = min(dfs_num[nbr], dfs_low[node]);
        }
    }
    if (isRoot and rootChildren > 1)
        answer[node] = 1;
}


int main()
{
#ifdef DEBUGUVA
    freopen("test","r", stdin);
    cout << "This is debug\n";
#endif
    string str;
    getline(cin, str);
    int nplaces = stoi(str);
    while(nplaces) {
        vector<vector<int>> adjlist(nplaces);
        while(getline(cin, str), str[0] != '0') {
            istringstream iss(str);
            int v1, v2;
            iss >> v1;
            v1--;
            while(not iss.eof()) {
                iss >> v2;
                v2--;
                adjlist[v1].push_back(v2);
                adjlist[v2].push_back(v1);
            }
        }
        vector<int> dfs_num(nplaces, UNVISITED),
                        dfs_low(nplaces, 1e9), answer(nplaces, 0);
        int num  = 0;
        for (int i = 0; i < nplaces; i++) {
            if (dfs_num[i] == UNVISITED)
                dfs(i, adjlist, num, dfs_low, dfs_num, answer, ROOT, -1);
        }
        cout << accumulate(answer.begin(), answer.end(), 0) << endl;

        getline(cin, str);
        nplaces = stoi(str);
    }

    return 0;
}
