/* Rishikesh
 * UVA 722 Lakes
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
#include<queue>
#include<list>
#include<deque>
#include<bitset>

using namespace std;

enum class Terrain {
    land,
    water
};

set<pair<int,int>> nbrs(int x, int y, vector<vector<Terrain>> &terrain) {
    set<pair<int, int>> ans;
    int dx[]{1, -1, 0, 0}, dy[]{0, 0, 1, -1};
    int m = terrain.size(), n = terrain[0].size();
    for (int i = 0; i < 4; i++) {
        int ax = x + dx[i], ay = y + dy[i];
        if (ax >= 0 and ay >= 0 and ax < m and ay < n
                and terrain[ax][ay] == Terrain::water)
            ans.insert(make_pair(ax, ay));
    }
    return ans;
}

int main() {
    string str;
    int M;
    getline(cin, str);
    M = stoi(str);
    getline(cin, str);
    for (int caseno = 1; caseno <= M; caseno++) {
        getline(cin, str);
        auto iss = istringstream(str);
        int wi, wj;
        iss >> wi >> wj; wi--; wj--;

        vector<vector<Terrain>> terrain;
        while(getline(cin, str), str.length() > 0) {
            vector<Terrain> v;
            for(char c: str) {
                if (c == '0')
                    v.push_back(Terrain::water);
                else
                    v.push_back(Terrain::land);
            }
            terrain.push_back(v);
        }

        int ans = 1, m = terrain.size(), n = terrain[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        visited[wi][wj] = 1;
        stack<pair<int, int>> st;
        st.push(make_pair(wi, wj));
        while(!st.empty()) {
            auto t = st.top();
            st.pop();
            for (auto p : nbrs(t.first, t.second, terrain)) {
                if (not visited[p.first][p.second]) {
                    ans++;
                    visited[p.first][p.second] = 1;
                    st.push(p);
                }
            }
        }

        cout << ans << "\n";
        if (caseno < M)
            cout <<"\n";
    }
}
