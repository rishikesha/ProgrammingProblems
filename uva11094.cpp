/* Rishikesh
 * UVA 11094 Continents
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

int flood(int x, int y, vector<vector<int>> &visited, vector<string> &terrain) {
    if (terrain[x][y] == 'w' or visited[x][y])
        return 0;
    int num = 1, M = terrain.size(), N = terrain[0].size();
    visited[x][y] = 1;
    int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};
    for (int i = 0 ; i < 4; i ++) {
        int ax = (M+x + dx[i]) % M, ay = y + dy[i];
        if(ax >= 0 and ax < M and ay >= 0 and ay < N
                and terrain[ax][ay] == 'l' and not visited[ax][ay]) {
            num += flood(ax, ay, visited, terrain);
        }
    }
    return num;
}

int main() {
    int M, N;
    string str;
    getline(cin, str);
    istringstream iss(str);
    iss >> M >> N;
    vector<string> terrain(M);
    for (int i = 0; i < M; i++)
        getline(cin, terrain[i]);
    getline(cin, str);
    iss = istringstream(str);
    int x,y;
    iss >> x >> y;

    vector<vector<int>> visited(M, vector<int>(N,0));
    flood(x, y, visited, terrain);
    int ans = 0;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            ans = max(ans, flood(i, j, visited, terrain));
        }
    }
    cout << ans << endl;
}
