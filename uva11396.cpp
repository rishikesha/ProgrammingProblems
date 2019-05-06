
/* Rishikesh
 * UVA 11396
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

using namespace std;

bool isBipartite(int node, int color, vector<int> &visitedColor, vector<vector<int>> &adjlist) {
    visitedColor[node] = color;
    int newColor = 1 + (2 - color);
    bool ans = true;

    for (int n : adjlist[node]) {
        if (not visitedColor[n]) {
            ans = ans and isBipartite(n, newColor, visitedColor, adjlist);
        } else {
            ans = ans and visitedColor[n] == newColor;
        }
        if (not ans)
            return false;
    }

    return true;

}


int main()
{
#ifdef DEBUG
    freopen("test", "r", stdin);
    cout << "This is a DEBUG\n";
#endif
    int nvertices;
    while(cin >> nvertices, nvertices) {
        vector<vector<int>> adjlist(nvertices);
        int t1, t2;
        while (cin >> t1 >> t2, t1) {
            adjlist[--t1].push_back(--t2);
            adjlist[t2].push_back(t1);
        }

        vector<int> visitedColor(nvertices, 0);

        bool ans = true;
        for (int i = 0; ans and  i < nvertices; i++) {
            if (not visitedColor[i]) {
                ans = ans and isBipartite(i, 1, visitedColor, adjlist);
            }
        }
        if (ans)
            cout << "YES\n";
        else {
            cout << "NO\n";
        }
    }
}

