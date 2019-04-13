#include<map>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    map<vector<int>, int> m;
    int n;
    while(cin >> n, n) {
        m.clear();
        while(n--) {
            vector<int> v(5);
            for(int i = 0; i < 5; i++) {
                cin >> v[i];
            }
            sort(v.begin(), v.end());
            m[v] += 1;
        }
        int maxval=0;
        for(auto it = m.begin(); it != m.end(); it++)
            maxval = max(maxval, it->second);
        int answer = 0;
        for(auto it = m.begin(); it != m.end(); it++)
            if (it->second == maxval)
                answer += maxval;
        printf("%d\n", answer);
    }
}
