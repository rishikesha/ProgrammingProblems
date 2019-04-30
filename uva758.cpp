/* Rishikesh
 * UVA 758 The Same Game
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

struct Score {
    int row, column, ballsremoved;
    char color;
    int points() { return (ballsremoved - 2) * (ballsremoved - 2);}
    Score (int r, int c, int br, char clr) : row(r), column(c), ballsremoved(br),
          color(clr) {}
};

class Same{
    private:
        vector<string> samegrid; // 'E' will denote empty cell
        int ncols, nrows;
        vector<Score> score; 
        void rearrange(); //rearange the blocks after once play
        bool findBest(); // find the best play
        vector<pair<int, int>> nbrs(pair<int,int> p);
    public:
        Same(vector<string> samegrid_) : nrows(samegrid_.size()),
            ncols(samegrid_[0].length()) {
            samegrid = std::move(samegrid_);
        }

        void playSame();
        void printscore();
};


int main() {
    int ngames;
    string str;
    getline(cin, str);
    ngames = stoi(str);
    getline(cin, str);
    for(int caseno = 1 ; caseno <= ngames; caseno++) {
        vector<string> samegrid;
        while(getline(cin, str), str.length() > 0) {
            samegrid.push_back(str);
        }
        Same same(samegrid);
        same.playSame();
        printf("Game %d:\n\n", caseno);
        same.printscore();
        if (caseno != ngames)
            printf("\n");
    }
}

void Same::rearrange() {
    bool ret = false;
    int hdisplace = 0;
    vector<int> emptycolumns;
    for (int j = 0 ; j < ncols; j++) {
        int vdisplace = 0;
        for (int i = nrows - 1; i >= 0; i--) {
            if (samegrid[i][j] == 'E') {
                vdisplace++;
            } else if (vdisplace) {
                swap(samegrid[i][j], samegrid[i+vdisplace][j]);
            }
        }
        if (hdisplace) {
            for (int i = 0; i< nrows; i++) {
                samegrid[i][j - hdisplace] = samegrid[i][j];
            }
        }
        if (vdisplace == nrows) {
            hdisplace++;
        }
    }
    ncols -= hdisplace;
}

void Same::playSame() {
    while(findBest()) {
        rearrange();
    }
}

bool Same::findBest() {
    int besti = -1, bestj = -1, mostBalls = 1;
    vector<vector<int>> visited(nrows, vector<int>(ncols,0));
    for (int j = 0 ; j < ncols; j++) {
        for (int i = nrows - 1; i >= 0; i--) {
            if (samegrid[i][j] == 'E')
                break;
            int nballs = 1;
            if (not visited[i][j]) {
                char clr = samegrid[i][j];
                stack<pair<int, int>> st;
                st.push(make_pair(i, j));
                visited[i][j] = 1;
                while (not st.empty()) {
                    auto top = st.top();
                    st.pop();
                    for (auto pp : nbrs(top)) {
                        if (not visited[pp.first][pp.second]) {
                            visited[pp.first][pp.second] = 1;
                            st.push(pp);
                            nballs++;
                        }
                    }
                }
            }
            if (nballs > mostBalls) {
                besti = i;
                bestj = j;
                mostBalls = nballs;
            }
        }
    }

    if (mostBalls > 1) {
        vector<vector<int>> visited(nrows, vector<int>(ncols,0));
        score.emplace_back(besti, bestj, mostBalls, samegrid[besti][bestj]);
        stack<pair<int, int>> st; st.push(make_pair(besti, bestj));
        visited[besti][bestj] = 1;
        while(not st.empty()) {
            auto t = st.top();
            st.pop();
            for (auto pp : nbrs(t)) {
                if(not visited[pp.first][pp.second]) {
                    st.push(pp);
                    visited[pp.first][pp.second] = 1;
                }
            }
            samegrid[t.first][t.second] = 'E';
        }
    }
    return mostBalls != 1;
}

vector<pair<int, int>> Same::nbrs(pair<int, int> p) {
    int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};
    vector<pair<int, int>> answer;
    for (int i = 0; i < 4; i++) {
        int ai = p.first + dx[i], aj = p.second + dy[i];
        if (ai >= 0 and ai < nrows and aj >= 0 and aj < ncols
                and samegrid[p.first][p.second] == samegrid[ai][aj]) {
            answer.push_back(make_pair(ai, aj));
        }
    }
    return answer;
}

void Same::printscore() {
    int ballsremaining = 150, sc = 0;
    for(int i = 0; i < score.size(); i++) {
        printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n",
                i + 1, 10 - score[i].row, score[i].column + 1, score[i].ballsremoved,
                score[i].color, score[i].points());
        ballsremaining -= score[i].ballsremoved;
        sc += score[i].points();
    }

    if (ballsremaining == 0)
        sc += 1000;

    printf("Final score: %d, with %d balls remaining.\n", sc, ballsremaining);
}
