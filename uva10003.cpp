/* Rishikesh
 * UVA 10003
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


int cut(vector<int> &lengths, vector<vector<int>> &costmatrix, int i, int j) {

    if (costmatrix[i][j] < 0) {
        int t = 1e9;
        for (int u = i+1; u <= j-1; u++) {
            t = min(t, cut(lengths, costmatrix, i, u) + cut(lengths, costmatrix, u, j));
        }
        costmatrix[i][j] = t + lengths[j] - lengths[i];
    } 
    return costmatrix[i][j];

}



int main() {
    int l;
    while(cin >> l, l > 0) {
        int n;
        cin >> n;

        vector<int> lengths(n+2,0);
        lengths[0] = 0; lengths[n+1] = l;
        for (int i =1; i <= n; i++)
            cin >> lengths[i];

        vector<vector<int>> costmatrix(n+2, vector<int>(n+2, -1));
        for (int i = 0; i <= n; i++)
            costmatrix[i][i+1] = 0;

        cout << "The minimum cutting is " << cut(lengths, costmatrix, 0, n+1) << "." << endl;
    }
}
