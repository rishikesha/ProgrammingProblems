#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>

using namespace std;

enum class FS {
    left, 
    right,
};


int main() {

    int ncases;
    scanf("%d\n", &ncases);
    while(ncases--) {
        queue<pair<int, int>> lcars, rcars;
        vector<pair<int, int>> answer;
        int n, t, m,currenttime = 0;;
        cin >> n >> t>> m;
        FS fs = FS::left;

        for(int i = 0; i<m; i++) {
            int tmp;
            string s;
            cin >> tmp >> s;
            if (s == "left") {
                lcars.push(make_pair(i, tmp));
            } else {
                rcars.push(make_pair(i, tmp));
            }
        }

        while (not (lcars.empty() and rcars.empty())) {
            if(fs == FS::left and not lcars.empty() and lcars.front().second <= currenttime) {
                int ncars = 0;
                while (not lcars.empty() and lcars.front().second <= currenttime and ncars < n) {
                    answer.push_back(make_pair(lcars.front().first, currenttime+t));
                    lcars.pop();
                    ncars++;
                }
                currenttime += t;
                fs = FS::right;
            }
            else if(fs == FS::right and not rcars.empty() and rcars.front().second <= currenttime) {
                int ncars = 0;
                while (not rcars.empty() and rcars.front().second <= currenttime and ncars < n) {
                    answer.push_back(make_pair(rcars.front().first, currenttime+t));
                    rcars.pop();
                    ncars++;
                }
                currenttime += t;
                fs = FS::left;
            } else if (fs == FS::left and not rcars.empty() and
                    (lcars.empty() or lcars.front().second > rcars.front().second)) {
                fs = FS::right;
                currenttime = max(currenttime, rcars.front().second) + t;
            } else if (fs == FS::right and not lcars.empty() and
                    (rcars.empty() or rcars.front().second > lcars.front().second)) {
                fs = FS::left;
                currenttime =  max(currenttime, lcars.front().second) + t;
            } else {
                int tmp = INT_MAX;
                if (not lcars.empty())
                    tmp = lcars.front().second;
                if (not rcars.empty())
                    tmp = min(tmp, rcars.front().second);
                currenttime = tmp;
            }
        }

        sort(answer.begin(), answer.end());
        for (auto p : answer) {
            cout << p.second << "\n";
        }
        if (ncases > 0) 
            cout <<  "\n";
    }
}
