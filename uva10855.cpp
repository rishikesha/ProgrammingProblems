#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<algorithm>
#include<sstream>
#include<cstdio>

using namespace std;

typedef long long ll;


void rotate(vector<string>& block) {
    int n = block.size();
    for (int i = 0; i< n/2; i++) {
        for(int j = i ; j < n - i - 1; j++) { //Can reduce the tmp variables but this is clearer
            char top, right, bottom, left;
            top = block[i][j];
            right = block[j][n-i-1];
            bottom = block[n-i-1][n-j-1];
            left = block[n-j-1][i];
            block[i][j] = left;
            block[j][n-i-1]= top;
            block[n-i-1][n-j-1]=right;
            block[n-j-1][i]=bottom;
        }
    }
}

int countMatches(vector<string>& large, vector<string>& small) {
    int ls = large.size(), ss = small.size();
    int answer = 0;

    for (int i = 0; i <= ls -ss; i++) {
        for (int j = 0; j <= ls - ss; j++) {
            bool match = true;
            for(int u =0; u < ss; u++) {
                for (int v=0; v< ss; v++) {
                    if (large[i+u][j+v] != small[u][v]) {
                        match = false;
                        break;
                    }
                }
                if (not match)
                    break;
            }
            if (match)
                answer++;
        }
    }

    return answer;
}


int main() {
    while (true) {
        vector<string> large, small;
        string s;
        int n, N, r[4];
        istringstream iss;

        //scanf("%d %d\n", &N, &n);
        getline(cin, s);
        iss = istringstream(s);
        iss >> N >>n;
        if (N==0)
            break;


        for (int i = 0; i < N; i++) {
            getline(cin, s);
            large.push_back(s);
        }
        for (int i = 0; i < n; i++) {
            getline(cin, s);
            small.push_back(s);
        }

        n = n;
        for(int i = 0; i < 4; i++) {
            r[i] = countMatches(large, small);
            rotate(small);
        }
        cout << r[0] << " "<< r[1] << " "<< r[2] << " "<< r[3] << "\n";
    }
}
