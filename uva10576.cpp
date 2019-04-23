/* Rishikesh
 * UVA 10576 Y2k Accounting Bug
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
#include<climits>

using namespace std;

int earnings[12];
int deficit, surplus;

int findMax(int n) {
    if (n < 5 or accumulate(earnings +(n-5), earnings+n, 0) <= 0) {
        if (n == 12)  {
            return accumulate(earnings, earnings+12, 0);
        }


        int l,r = INT_MIN;
        earnings[n] = surplus;
        r = findMax(n+1);

        earnings[n] = -deficit; 
        l = findMax(n+1);

        return max(l,r);

    } else
        return INT_MIN;
}


int main() {
    string s;
    while(getline(cin, s), s.length()) {
        istringstream iss(s);
        iss >> surplus >> deficit;
        int r = findMax(0);
        if (r > 0) {
            cout << r << endl;
        } else {
            cout << "Deficit\n";
        }
    }
}
