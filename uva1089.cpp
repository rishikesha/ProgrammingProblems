#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

void processMatrix(int m, int n) {
    string s;
    istringstream iss;

    vector<vector<int>> transpM(n+1), transpP(n+1);

    for(int i = 1; i <= m; i++) {
        vector<int> position;

        getline(cin,s); iss = istringstream(s);
        int ct;
        iss >> ct;
        for (int j = 0; j < ct; j++) {
            int tmp; iss>> tmp;
            position.push_back(tmp);
            transpP[tmp].push_back(i);
        }

        getline(cin,s); iss = istringstream(s);
        for (int j = 0; j < ct; j++) {
            int tmp; iss>> tmp;
            transpM[position[j]].push_back(tmp);
        }
    }

    cout << n << " " <<m << endl;
    for(int i=1; i <= n; i++) {
        cout << transpP[i].size();
        for(auto dd : transpP[i]) {
            cout << " " << dd;
        }
        cout << endl;
        for(int k = 0; k < transpM[i].size(); k++) {
            if (k != 0)
                cout << " ";
            cout  << transpM[i][k];
        }
        cout << endl;
    }
}

int main() {
    string s;
    istringstream iss;

    while(getline(cin, s), s.length()) {
        iss = istringstream(s);
        int m,n;
        iss >> m >> n;
        processMatrix(m,n);
    }

}
