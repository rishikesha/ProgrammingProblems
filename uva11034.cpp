#include<iostream>
#include<queue>
#include<string>


using namespace std;

enum class FS {
    left,
    right,
};

int main() {
    int ncases;
    cin >> ncases;
    while(ncases--) {
        int l,m;
        cin >> l >> m;
        l *= 100;
        queue<int> lcars, rcars;

        for (int i = 0; i < m; i++) {
            int t; string s;
            cin >> t >> s;
            if (s == "left") {
                lcars.push(t);
            } else {
                rcars.push(t);
            }
        }
        
        int ntrips = 0;
        FS fs = FS::left;

        while(lcars.size() or rcars.size()) {
            if (fs == FS::left and lcars.size()) {
                int currlength = 0;
                while(not lcars.empty() and currlength < l) {
                    if (currlength + lcars.front() <= l) {
                        currlength += lcars.front();
                        lcars.pop();
                    } else {
                        break;
                    }
                }
                ntrips++;
                fs = FS::right;
            } else if (fs == FS::right and not rcars.empty()) {
                int currlength = 0;
                while(not rcars.empty() and currlength < l) {
                    if (currlength + rcars.front() <= l) {
                        currlength += rcars.front();
                        rcars.pop();
                    } else {
                        break;
                    }
                }
                ntrips++;
                fs = FS::left;
            } else {
                if (fs == FS::left) 
                    fs = FS::right;
                else
                    fs = FS::left;
                ntrips++;
            }
        }
        cout << ntrips << endl;
    }
}
