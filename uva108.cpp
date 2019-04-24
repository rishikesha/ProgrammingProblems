/* Rishikesh
 * UVA 108 Maximum Sum
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
    int N;
    cin >> N;
    int sums[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int x, t=0; cin >> x;
            if (i > 0) {
                t += sums[i-1][j];
            }
            if (j > 0) {
                t += sums[i][j-1];
            }
            if (i > 0 and j > 0) {
                t -=sums[i-1][j-1];
            }
            sums[i][j] = t+x;
        }
    }

    int answer = -1e9;
    for (int i1 = 0; i1 < N; i1++) {
        for (int j1 = 0; j1 < N; j1++) {
            for (int i2 = i1; i2 < N; i2++) {
                for (int j2 =j1; j2 < N; j2++) {
                    int t = sums[i2][j2];
                    if (i1 > 0)
                        t -= sums[i1-1][j2];
                    if (j1 > 0)
                        t -= sums[i2][j1-1];
                    if (i1 > 0 and j1 > 0)
                        t += sums[i1-1][j1-1];

                    if (t > answer) {
                        //cout << i1 << "," << j1 << "  " << i2 << "," <<j2 << "---" << answer<< endl;
                        answer = t;
                    }

                }
            }
        }
    }
    cout << answer<< endl;

}
