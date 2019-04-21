/* Rishikesh
 * UVA 11553 Grid Game
 * Bob always chooses.
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

using namespace std;


int main() {
    int ncases;
    cin >> ncases;
    while(ncases--) {
        int n; cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));
        vector<int> ind(n);
        for(int i=0; i< n; i++)
            for(int j = 0; j< n; j++)
                cin >> grid[i][j];

        iota(ind.begin(), ind.end(), 0);
        int bestscore=1e9;
        do {
            int score = 0;
            for (int i = 0; i< n; i++) {
                score += grid[i][ind[i]];
            }
            bestscore = min(bestscore, score);
        }while(next_permutation(ind.begin(), ind.end()));
        cout << bestscore << endl;
    }
}
