/* Rishikesh
 * UVA 12442 Forwarding emails
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
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        int N; cin >> N;
        vector<int> forwardsTo(N,0), depth(N), visited(N,0);

        for (int i = 0; i < N; i++) {
            int from, to;
            cin >> from >> to;
            forwardsTo[--from] = --to; // 0 based numbering of Martians
        }

        int bestperson = 0;
        int mostreached = 0;
        for(int i = 0; i < N; i++) {
            int count = 0, k;
            stack<int> st;
            for (k = i; not visited[k]; k = forwardsTo[k]) {
                st.push(k);
                visited[k] = true;
            }

            if (depth[k] == 0) { // a cycle
                count = st.size();
                while(not st.empty()) {
                    depth[st.top()] = count;
                    st.pop();
                }
            } else { // a chain
                count = depth[k];
                while(not st.empty()) {
                    count++;
                    depth[st.top()] = count;
                    st.pop();
                }
            }

            if (count > mostreached) {
                bestperson = i;
                mostreached = count;
            }
        }
        cout << "Case " << t << ": " << ++bestperson << endl;
    }
}
