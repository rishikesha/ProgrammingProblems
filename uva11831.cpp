/* Rishikesh
 * UVA 11831 Sticker Collector Robot
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
#include<regex>

using namespace std;
char directions[]{'N', 'L', 'S', 'O'};
map<char, int> dirindex{{'N', 0}, {'L', 1}, {'S', 2}, {'O', 3}};

void updateAnswerArena(int &ans, vector<string> &arena, int x, int y) {
    if (arena[y][x] == '*') {
        ans++;
        arena[y][x] = '.';
    }
}

int main() {
    string str;
    int n,m,s;
    while(getline(cin, str), str[0] != '0')  {
        istringstream iss(str);
        iss >> n >> m >> s;

        vector<string> arena(n);
        for(int i = 0; i < n; i++) {
            getline(cin, arena[i]);
        }

        string instructions;
        getline(cin, instructions);

        int x,y=-1;
        char orientation;
        {
            regex initloc("(N|S|O|L)");
            smatch sm;
            for (y = 0; y < n; y++) {
                if (regex_search(arena[y],sm,initloc)) {
                    x = sm.position();
                    orientation = arena[y][x];
                    break;
                }
            }
        }

        int ans = 0; 
        for (int i = 0; i < instructions.length(); i++) {
            switch(instructions[i]) {
                case 'D':
                    orientation = directions[(dirindex[orientation] + 1) % 4];
                    break;
                case 'E':
                    orientation = directions[(dirindex[orientation] + 3) % 4];
                    break;
                case 'F':
                    switch(orientation) {
                        case 'N':
                            if (y != 0 and arena[y - 1][x] != '#') {
                            y--;
                            updateAnswerArena(ans, arena, x, y);
                            }
                            break;
                        case 'S':
                            if (y != n - 1 and arena[y + 1][x] != '#') {
                                y++;
                                updateAnswerArena(ans, arena, x, y);
                            }
                            break;
                        case 'O':
                            if (x != 0 and arena[y][x - 1] != '#') {
                                x--;
                                updateAnswerArena(ans, arena, x, y);
                            }
                            break;
                        case 'L':
                            if (x != m - 1 and arena[y][x+1] != '#') {
                                x++;
                                updateAnswerArena(ans, arena, x, y);
                            }
                            break;
                    }
                    break;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
