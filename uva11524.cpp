/* Rishikesh
 * UVA  11524 Fire
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

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, -1, 1};

int main() {
#ifdef DEBUGUVA
    freopen("test", "r", stdin);
    cout << "This is a DEBUG\n";
#endif

    int ncases;
    string s;
    getline(cin, s);
    istringstream iss(s);
    iss >> ncases;
    while(ncases--){
        int R,C;
        vector<string> maze;

        getline(cin, s);
        iss = istringstream(s);
        iss >> R >> C;

        queue<pair<int,int>> qFire, qJoseph;
        for(int r = 0; r < R; r++){
            int rJ, rF, cJ, cF;
            getline(cin, s);
            maze.push_back(s);
            if (s.find('F') != string::npos) {
                cF = s.find('F');
                rF = r;
                qFire.push(pair<int,int>(rF, cF));
            }

            if (s.find('J') != string::npos) {
                cJ = s.find('J');
                rJ = r;
                qJoseph.push(pair<int,int>(rJ, cJ));
            }
        }

        bool success = false;
        int numSteps = 0;

        while(not success and not  qJoseph.empty()) {
            int qFlength = qFire.size();
            int qJLength = qJoseph.size();
            for (int i = 0; i < qFlength; i++)
            {
                int r=qFire.front().first, c = qFire.front().second;
                qFire.pop();
                for (int j = 0; j < 4; j++) {
                    int u = r + dr[j], v = c + dc[j];
                    if (u >= 0 and u < R and v >= 0 and v < C
                                    and maze[u][v] != 'F' and
                                    maze[u][v] != '#') {
                        qFire.push(pair<int, int>(u,v));
                        maze[u][v] = 'F';
                    }
                }
            }

            for (int i = 0; not success and i < qJLength; i++) {
                int r = qJoseph.front().first, c = qJoseph.front().second;
                qJoseph.pop();
                success =  (c == 0 or c == C - 1 or r == 0 or r == R - 1);
                for (int j = 0; not success and j < 4; j++) {
                    int u = r + dr[j], v = c + dc[j];
                    if (u >= 0 and u < R and v >= 0 and v < C and
                                    maze[u][v] != 'F' and maze[u][v] != '#' and
                                    maze[u][v] != 'J') {
                        qJoseph.push(pair<int, int>(u,v));
                        maze[u][v] = 'J';
                    }
                }
            }
            numSteps += 1;
        }
        if (success) {
            cout << numSteps << endl;
        } else {
            cout << "IMPOSSIBLE\n";
        }
    }
}
