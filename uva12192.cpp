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
/*
class LargestSquare {
    private:
        vector<vector<int>> H;

    public:
        LargestSquare(vector<vector<int>> &H_) {
            H = move(H_);
        }

};*/

void printLargestArea(int l, int u, vector<vector<int>> &H) {
    vector<int> L, U;
    for (vector<int> h : H) {
        auto first = lower_bound(h.begin(), h.end(), l);
        if (first == h.end())
            continue;
        L.push_back(first - h.begin());
        auto second = upper_bound(h.begin(), h.end(), u);
        U.push_back(second - h.begin());

    }
    vector<int> v;
    for (int i= 0; i < L.size(); i++) {
        for (int j = i; j < L.size(); j++) {
            v.push_back(min(j-i+1, U[j] - L[i]));
        }
    }
    if (v.size()) {
        cout << *max_element(v.begin(), v.end()) << endl;
    } else 
        cout << 0 << endl;
}


int main() {
    int n,m;
    while(cin >> n>>m, n>0) {
        vector<vector<int>> H(n,vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> H[i][j];
            }
        }

        int q; cin >> q;
        while(q--) {
            int l, u;
            cin >> l >> u;
            printLargestArea(l, u, H);
        }

        cout << "-\n";
    }

}
