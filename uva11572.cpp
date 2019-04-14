/* Rishikesh
 * uva11572
 */

#include<map>
#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> m;
    while (n--) {
        int t;
        cin >> t;
        m.clear();

        int maxcount = 0;
        int laststart = 1;
        for(int i = 1; i<= t;i++) {
            int tmp;
            cin >> tmp;
            if (m[tmp] >= laststart ) {
                maxcount = max(maxcount, i-laststart);
                laststart = m[tmp]+1;
            } 
            m[tmp] = i;
        }
        maxcount = max(maxcount, t-laststart+1);
        cout << maxcount << endl;
    }
}
