#include<vector>
#include<iostream>
#include<string>
#include<sstream>
#include<map>

using namespace std;

int main() {
    string s;
    istringstream iss;
    while(getline(cin, s), s.length()) {
        int n,m;
        iss = istringstream(s);
        iss >> n >> m;
        map<int, vector<int>> positions;

        getline(cin,s); iss = istringstream(s);
        for(int i = 1; i <= n; i++) {
            int t; iss >> t;
            positions[t].push_back(i);
        }

        for (int i = 0; i < m; i++) {
            getline(cin,s); iss = istringstream(s);
            int num, pos; iss >> pos >> num;
            if (pos > positions[num].size()) {
                cout << 0 << endl;
            } else {
                cout << positions[num][pos-1] << endl;
            }
        }
    }

}
