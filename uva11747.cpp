/* Rishikesh
 * UVA  11747 Heavy Cycle Edges
 * Simple MST problem
 * Compute the MST. Every other edge is a highest weight edge of
 * a cycle. The list of weights are unique but the egdges are not
 * unique since MST is not unique.
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
    while (cin >> n >> m, m != 0 or n != 0) {
        set<tuple<int, int, int>> edge, edge2;
        for (int i = 0; i < m; i ++) {
            int t1, t2, t3;
            cin >> t1 >> t2 >> t3;
            edge.insert(make_tuple(t3, t1, t2));
        }

        UnionFind uf(n);
        for(auto e : edge) {
            int x = get<1>(e);
            int y = get<2>(e);
            if (uf.find(x) != uf.find(y)) {
                uf.un(x,y);
            } else {
                edge2.insert(e);
            }
        }

        if (edge2.size() == 0) {
            cout << "forest" << endl;
        } else {
            auto it = edge2.begin();
            cout << get<0>(*it);
            for (++it; it != edge2.end(); it++) {
                cout << " " << get<0>(*it);
            }
            cout << "\n";
        }
    }
}



