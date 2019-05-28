/* Rishikesh
 * UVA  11631 Dark Roads
 * Simple MST problem
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
#include<cmath>
#include<queue>

using namespace std;
class UnionFind {
private:
    vector<int> parent;
public:
    UnionFind(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void un(int x, int y) {
        int a = find(x);
        int b = find(y);
        if (a != b) {
            parent[b] = a;
        }
    }
};


int main() {
#ifdef DEBUGUVA
    freopen("test", "r", stdin);
    cout << "This is a DEBUG\n";
#endif
    int m, n;
    while (cin >> m >> n, m != 0 or n != 0) {
        vector<tuple<int, int, int>> road;
        int oldcost = 0;
        for (int i = 0; i < n; i ++) {
            int t1, t2, t3;
            cin >> t1 >> t2 >> t3;
            oldcost += t3;
            road.emplace_back(t3, t1, t2);
        }
        sort(road.begin(), road.end());
        set<int> vertices;
        int i = 0, newcost = 0, nroads = 0;
        UnionFind uf(m);
        while(nroads != m - 1) {
            int d = get<0>(road[i]);
            int x = get<1>(road[i]);
            int y = get<2>(road[i]);
            if (uf.find(x) != uf.find(y)) {
                uf.un(x, y);
                newcost += d;
                nroads++;
            }
            i++;
        }
        cout << oldcost - newcost << endl;
    }
}



