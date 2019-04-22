/* Rishikesh
 * UVA 10567
 * Helping Fill Bates
 * The hint from cp3 book was very helpful
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

int main() {
    map<char, vector<int>> mm;
    string s;
    int q;
    cin >> s;
    for (size_t i=0; i< s.length(); i++) {
        mm[s[i]].push_back(i);
    }

    cin >> q;
    while(q--) {
        cin >> s;
        int found = true;
        int first = *upper_bound(mm[s[0]].begin(), mm[s[0]].end(), -1);
        int last = first;
        for (size_t i = 1; i< s.length(); i++) {
            auto it = upper_bound(mm[s[i]].begin(), mm[s[i]].end(), last);
            if (it == mm[s[i]].end()) {
                found = false;
                break;
            }
            last = *it;
        }
        if (found) {
            cout << "Matched " <<first << " " << last << endl;
        } else {
            cout << "Not matched\n";
        }
    }
}

