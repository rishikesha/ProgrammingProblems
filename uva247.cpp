/* Rishikesh
 * UVA 247 Calling circles
 * Doesn't pass the uva judge althouh I have not been
 * able to find and example where it does not work.
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

const int UNVISITED = 0;

void dfs(int node,
         int &num,
         vector<set<int>> &adjlist,
         vector<int> &dfs_num,
         vector<int> &dfs_low,
         stack<int> &S,
         vector<int> &instack,
         vector<vector<int>> &answer) {
    dfs_low[node] = dfs_num[node] = ++num;
    S.push(node); instack[node] = true;
    for (auto nbr : adjlist[node]) {
        if (dfs_num[nbr] == UNVISITED) {
            dfs(nbr, num, adjlist, dfs_num, dfs_low, S, instack, answer);
        }
        if (instack[nbr]) {
            dfs_low[node] = min(dfs_low[nbr], dfs_low[node]);
        }

    }
    if (dfs_low[node] == dfs_num[node]) {
        vector<int> concomp;
        while(true){
            int t = S.top();
            S.pop();
            instack[t] = false;
            concomp.push_back(t);
            if (node == t)
                break;
        }
        answer.push_back(concomp);
    }

}


int main() {
#ifdef DEBUGUVA
    freopen("test", "r", stdin);
#endif
    int n, m, ds = 1 ;
    while (cin >> n >> m, n > 0) {
        if (m == 0) {
        cout << "Calling circles for data set " << ds++ << ":\n" << endl;
            continue;
        }
        map<string, int> nToi;
        vector<string> iTon;
        vector<set<int>> adjlist(n);
        for(int i = 0; i < m; i++) {
            string str1, str2;
            cin >> str1 >> str2;
            if (nToi.count(str1) == 0) {
                iTon.push_back(str1);
                nToi[str1] = iTon.size() -1;
            }
            if (nToi.count(str2) == 0) {
                iTon.push_back(str2);
                nToi[str2] = iTon.size() -1;
            }
            adjlist[nToi[str1]].insert(nToi[str2]);
        }

        vector<int> dfs_num(n, 0), dfs_low(n, 1e9), instack(n, 0);
        vector<vector<int>> answer;
        stack<int> S;
        int num = 0;
        for (int i = 0; i < n; i++) {
            if (dfs_num[i] == UNVISITED) {
                dfs(i, num, adjlist, dfs_num, dfs_low, S, instack, answer );
            }
        }

        cout << "Calling circles for data set " << ds++ << ":" << endl;
        for(auto v : answer) {
            cout << iTon[v[0]];
            for (int i = 1; i < v.size(); i++)
                cout << ", " << iTon[v[i]];
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}
