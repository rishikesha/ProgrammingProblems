/* Rishikesh
 * UVA 12192 Grapevine
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

class LargestSquare {
    private:
        vector<vector<int>> diagonals;

    public:
        LargestSquare(vector<vector<int>> &H) {
            int n = H.size();
            int m = H[0].size();
            diagonals.resize(m+n-1);
            int ind = 0;
            for(int i = 0; i < n; i++) {
                for(int j = 0; i+j < n and j < m;  j++) {
                    diagonals[ind].emplace_back(H[i+j][j]);
                }
                ind++;
            }
            for(int i = 1; i < m; i++) {
                for(int j=0; i+j < m and j < n; j++) {
                    diagonals[ind].emplace_back(H[j][i+j]);
                }
                ind++;
            }
        }

        int getLargestSquare(int l, int u) {
            int answer = 0;
            for (int i = 0; i < diagonals.size(); i++) {
                auto it = lower_bound(diagonals[i].begin(), diagonals[i].end(), l);
                if (it == diagonals[i].end())
                    continue;
                int sqsize = upper_bound(diagonals[i].begin(), diagonals[i].end(), u)-it;
                answer = max(answer, sqsize);
            }
            return answer;
        }
};

int main() {
    int n,m;
    while(cin >> n>>m, n>0) {
        vector<vector<int>> H(n,vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> H[i][j];
            }
        }
        LargestSquare ls(H);

        int q; cin >> q;
        while(q--) {
            int l, u;
            cin >> l >> u;
            cout << ls.getLargestSquare(l,u) << endl;
        }
        cout << "-\n";
    }
}
