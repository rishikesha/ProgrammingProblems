/* Rishikesh
 * UVA  11101 Mall Mania
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

struct Point {
    int x,y;
    Point(int x_, int y_) : x(x_), y(y_){}
};

void neighbors(Point p, vector<Point>& answer) {
    answer.clear();
    int x = p.x, y = p.y;

    if (x > 0)
        answer.emplace_back(x-1, y);
    if (y > 0)
        answer.emplace_back(x, y-1);
    if (x < 2000)
        answer.emplace_back(x+1, y);
    if (y < 2000)
        answer.emplace_back(x, y+1);
}

int main() {
#ifdef DEBUGUVA
    freopen("test", "r", stdin);
    cout << "This is a DEBUG\n";
#endif
    int p1, p2, x, y;
    while(cin >> p1, p1 > 0) {
        vector<vector<int>> grid1(2001, vector<int>(2001, -1)),
                        grid2(2001, vector<int>(2001, -1));
        queue<Point> q1, q2;

        for(int i = 0; i < p1; i++) {
            cin >> x >> y;
            grid1[x][y] = 0;
            q1.emplace(x,y);
        }

        cin >> p2;
        for(int i = 0; i < p2; i++) {
            cin >> x >> y;
            grid2[x][y] = 0;
            q2.emplace(x,y);
        }

        vector<Point> nbrs;

        bool done = false;
        int answer = 0;
        while(not done) {
            Point pt1 = q1.front();
            q1.pop();
            neighbors(pt1, nbrs);
            for(auto pt : nbrs) {
                if (grid2[pt.x][pt.y] >= 0) {
                    done = true;
                    answer = grid2[pt.x][pt.y] + grid1[pt1.x][pt1.y] + 1;
                    break;
                }
                if (grid1[pt.x][pt.y] < 0) {
                    grid1[pt.x][pt.y] = grid1[pt1.x][pt1.y] + 1;
                    q1.emplace(pt.x, pt.y);
                }
            }

            if (done)
                break;

            Point pt2 = q2.front();
            q2.pop();
            neighbors(pt2, nbrs);
            for(auto pt : nbrs ) {
                if (grid1[pt.x][pt.y] >= 0) {
                    done = true;
                    answer = grid1[pt.x][pt.y] + grid2[pt2.x][pt2.y] + 1;
                    break;
                }
                if (grid2[pt.x][pt.y] < 0) {
                    grid2[pt.x][pt.y] = grid2[pt2.x][pt2.y] + 1;
                    q2.emplace(pt.x, pt.y);
                }
            }
        }

        cout << answer << endl;

    }


}



