/* Rishikesh
 * UVA  11228 Transportation Systems
 * Use Kruksal, record the distance as roadDist
 * under the distance exceeds state threshhold.
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

long long dist(pair<int, int> p1, pair<int,int> p2) {
    long long a = p1.first - p2.first;
    long long b = p1.second - p2.second;
    return (a*a + b*b);
}

class UnionFind {
private:
    vector<int> parent, rank;

    int ncomponents;
public:
    UnionFind(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        rank.resize(n, 1);
        ncomponents = n;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        else {
            parent[x] = find(parent[x]);
            return parent[x];
        }
    }

    void un(int x, int y) {
        int a = find(x), b = find(y);
        if (a == b)
            return;
        if (rank[a] < rank[b]) {
            parent[a] = b;
        } else {
            parent[b] = a;
        }
        ncomponents--;
    }
};


int main() {
#ifdef DEBUGUVA
    freopen("test", "r", stdin);
    cout << "This is a DEBUG\n";
#endif
    int ncases;
    cin >> ncases;
    for(int caseno = 1; caseno <= ncases; caseno++) {
        int n, r;
        cin >> n >> r;
        int rsq = r * r;
        vector<pair<int,int>> cities;
        priority_queue<tuple<long long, int, int>,
                vector<tuple<double, int, int>>,
                greater<tuple<double, int, int>>> pq;

        for (int i = 0 ; i < n; i++) {
            int t1, t2;
            cin >> t1 >> t2;
            cities.emplace_back(t1, t2);
            for (int j = 0; j < i; j++) {
                pq.push(make_tuple(dist(cities[i], cities[j]), j, i));
            }
        }
        UnionFind uf(n);
        int numstates = 0;
        double roadDist = 0.0, trainDist = 0.0;
        for (int i = 0; i < (n-1); i++) {
            int x, y, d;
            do {
                auto t = pq.top();
                pq.pop();
                d = get<0>(t);
                x = get<1>(t);
                y = get<2>(t);
            } while(uf.find(x) == uf.find(y));
            if (d > rsq)  {
                numstates++;
                trainDist += sqrt(d);
            } else
                roadDist += sqrt(d);
            uf.un(x, y);
        }
        printf("Case #%d: %d %d %d\n", caseno, numstates+1, lround(roadDist)
               , lround(trainDist));
    }
}
