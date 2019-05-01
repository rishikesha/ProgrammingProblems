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

int flood(int x, int y, char land, vector<vector<int>> &visited, vector<string> &terrain) {
    if (terrain[x][y] != land or visited[x][y])
        return 0;
    int num = 1, M = terrain.size(), N = terrain[0].size();
    visited[x][y] = 1;
    int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};
    for (int i = 0 ; i < 4; i ++) {
        int ax = x + dx[i], ay = (N + y + dy[i]) % N;
        if(ax >= 0 and ax < M and terrain[ax][ay] == land
                and not visited[ax][ay]) {
            num += flood(ax, ay, land, visited, terrain);
        }
    }
    return num;
}

int main() {
    int M, N;
    string str;
    while(getline(cin, str), str.length() > 0) {
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
        flood(x, y, terrain[x][y], visited, terrain);
        int ans = 0;
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                ans = max(ans, flood(i, j, terrain[x][y], visited, terrain));
            }
        }
        cout << ans << endl;

        getline(cin, str);
    }
}
