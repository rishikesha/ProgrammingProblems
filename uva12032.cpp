/* Rishikesh
 * UVA 12032 The monkey and the oiled bamboo
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

bool simulated(vector<int>& r, int jump) {
    int currentposition = 0;
    for (int i = 0; i < r.size(); i++) {
        if (r[i] - currentposition > jump)
            return false;
        if (r[i] - currentposition == jump)
            jump--;
        currentposition = r[i];
    }
    return true;
}

int main() {
    int ncases;
    cin >> ncases;
    for (int caseno=1; caseno <= ncases; caseno++) {
        int n; cin >> n;
        vector<int> r(n);
        for(int i = 0; i < n; i++)
            cin >> r[i];
        int minjump = r[0], maxjump = r[n-1]; //maxjump will surely take monkey to the top

        while(minjump < maxjump) {
            int mid = (minjump + maxjump)/2;
            if(simulated(r, mid))
                maxjump = mid;
            else
                minjump = mid + 1;
        }

        printf("Case %d: %d\n", caseno, minjump);
    }
}
