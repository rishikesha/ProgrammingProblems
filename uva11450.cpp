/* Rishikesh
 * UVA 11450 Wedding Shopping
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

void fill(vector<vector<int>> &garments, vector<vector<int>> &dp, int g, int m) {
    dp[g][m] = -1;
    for (int j = 0; j < garments[g-1].size();j++) {
        if (garments[g-1][j] > m)
            break;
        if (dp[g-1][m-garments[g-1][j]] < 0)
            break;
        dp[g][m] = max(dp[g][m], dp[g-1][m-garments[g-1][j]] +garments[g-1][j]);
    }
}

int main() {
    int ncases;
    cin >> ncases;
    while(ncases--) {
        int m,c;
        cin >> m >> c;
        vector<vector<int>> garments(c);
        for (int i = 0; i < c ;i++) {
            int num; cin >> num;
            garments[i].resize(num);
            for (int j = 0; j < num; j++)
                cin >> garments[i][j];

            sort(garments[i].begin(), garments[i].end());
        }

        vector<vector<int>> dp(c+1,vector<int>(m+1));
        for (int i = 0; i < m+1; i++)
            dp[0][i] = 0;
        for (int i = 1; i < c+1; i++)
            dp[i][0] = -1;

        for (int i = 1; i< c+1; i++) {
            for (int j = 1; j< m+1; j++) {
                fill(garments, dp, i, j);
            }
        }

        if (dp[c][m] > 0)
            cout << dp[c][m] << endl;
        else
            cout << "no solution" << endl;
    }
}

