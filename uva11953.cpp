/* Rishikesh
 * UVA 11953 Battleships
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
#include<functional>

using namespace std;

int checkship(int r, int c, vector<string> &seagrid, vector<vector<int>> &visited) {
    int ans = (seagrid[r][c] == 'x' ? 1 : 0);
    visited[r][c] = 1;
    int N = seagrid.size();
    int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
    for (int i = 0; i < 4; i++) {
        int r1 = r + dx[i], c1 = c + dy[i];
        if (r1 >= 0 and r1 < N and c1 >= 0 and c1 < N and not visited[r1][c1]
                and (seagrid[r1][c1] == 'x' or seagrid[r1][c1] == '@')) {
            ans += checkship(r1, c1,  seagrid, visited);
        }
    }
    return (ans > 0 ? 1 : 0);
}

int main() {
    int T;
    string str;
    getline(cin, str);
    istringstream iss(str);
    iss >> T;
    for(int caseno = 1; caseno <= T; caseno++) {
        getline(cin, str);
        int N = stoi(str);
        vector<string> seagrid(N);
        for(int i = 0; i < N; i++)
            getline(cin, seagrid[i]);

        vector<vector<int>> visited(N, vector<int>(N,0));
        int ans = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if (not visited[i][j])
                    ans += checkship(i, j, seagrid, visited);
            }
        }
        printf("Case %d: %d\n", caseno, ans);
    }
}
