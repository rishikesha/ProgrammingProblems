/* Rishikesh
 * UVA 11906 
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

set<pair<int, int>> neighbors(int x, int y, int M, int N, vector<vector<int>> &grid) {
    set<pair<int, int>> answer;
    int R = grid.size(), C = grid[0].size();
    int dx[8]{M, M, -M, -M, N, N, -N, -N};
    int dy[8]{N, -N, N, -N, M, -M, M, -M};
    for (int i = 0; i < 8; i++) {
        int xp = x + dx[i], yp = y + dy[i];
        if (xp >= 0 and xp < R and yp >= 0 and yp < C and grid[xp][yp] >= 0) {
            answer.insert(make_pair(xp, yp));
        }
    }
    return answer;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int R, C, M, N, W;
        cin >> R >> C >> M >> N >> W;
        vector< vector<int> > grid(R, vector<int>(C, 0)), visited(R, vector<int>(C, 0));
        for (int i = 0; i < W; i++) {
            int x, y;
            cin >> x >> y;
            grid[x][y] = -1;
        }
        stack<pair<int, int>> st;

        st.push(make_pair( 0,0));
        visited[0][0] = 1;
        while(not st.empty()) {
            pair<int, int> top = st.top();
            st.pop();
            set<pair<int, int>> nbrs = neighbors(top.first, top.second, M, N, grid);
            for (auto p : nbrs) {
                if (not visited[p.first][p.second]){
                    st.push(p);
                    visited[p.first][p.second] = 1;
                }
                grid[p.first][p.second] += 1;
            }
        }

        int odd = 0, even = 0;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if(grid[i][j] > 0) {
                    if (grid[i][j] & 1)
                        odd++;
                    else {
                        even++;
                    }
                }

            }
        }

        if (even + odd == 0) //This is the case when knight just does not move from starting position
            even = 1;
        cout << "Case "  << t << ": " << even << " " << odd << endl;


    }
}
