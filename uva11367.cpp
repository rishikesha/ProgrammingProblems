/* Rishikesh
 * UVA  11367 Full Tank
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
#include<list>
#include<forward_list>


using namespace std;

typedef pair<int, int> State; //city and gasleft

void solve(vector<int>& prices, vector<forward_list<pair<int, int>>>& roads,
           int capacity, int start, int end) {
    int mincost[1001][101];
    for (int i = 0; i < 1001; i++) {
        fill(mincost[i], mincost[i]+101, 1e9);
    }
    mincost[start][0] = 0;
    priority_queue<pair<int, State>, vector<pair<int, State>>, greater<pair<int, State>>> pq;
    pq.push(make_pair(0, State(start, 0)));
    while (not pq.empty()) {
        int cost = pq.top().first;
        int city = pq.top().second.first;
        int fuel = pq.top().second.second;
        pq.pop();
        if (city == end) {
            cout << cost << endl;
            return;
        }

        if (fuel < capacity) {
            mincost[city][fuel+1] = cost + prices[city];
            pq.push(make_pair(cost + prices[city], make_pair(city, fuel+1)));
        }

        for (auto road : roads[city]){
            if (fuel >= road.second and
                    mincost[road.first][fuel - road.second] > cost){
                mincost[road.first][fuel - road.second] = cost;
                pq.push(make_pair(cost,
                                  make_pair(road.first, fuel - road.second)));
            }
        }
    }
    cout << "impossible\n";
}


int main() {
#ifdef DEBUGUVA
    freopen("test", "r", stdin);
    cout << "This is DEBUG compilation\n";
#endif

    int n, m;
    cin >> n >> m;
    vector<int> prices(n);
    vector<forward_list<pair<int, int>>> roads(n);

    for(int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    for(int i = 0 ; i < m; i++) {
        int c1, c2, d;
        cin >> c1 >> c2 >> d;
        roads[c1].push_front(pair<int, int>(c2, d));
        roads[c2].push_front(pair<int, int>(c1, d));
    }

    int nqueries;
    cin >> nqueries;

    while(nqueries--){
        int capacity, start, end;
        cin >> capacity >> start >> end;
        solve(prices, roads, capacity, start, end);
    }



}
