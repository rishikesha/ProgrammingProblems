#include<iostream>
#include<bitset>
#include<string>

using namespace std;


int weight[1<<16];
int potency[1<<16];

int main() {
    string s;
    while(true) {
        getline(cin,s);
        if (s.length() == 0) {
            break;
        }

        int m =  stoi(s);
        int n = 1 << m;
        for(int i = 0; i < n; i++) {
            getline(cin,s);
            weight[i] = stoi(s);
        }

        for (unsigned long long i = 0; i < n; i++) {
            potency[i] = 0;
            bitset<16> b(i);
            for(unsigned long long j = 0; j < m; j++) {
                b.flip(j);
                int ind = b.to_ulong();
                potency[i] += weight[ind];
                b.flip(j);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            bitset<16> b(i);
            for(int j = 0; j < m; j++) {
                b.flip(j);
                int ind = b.to_ulong();
                ans = max(ans, potency[i] + potency[ind]);
                b.flip(j);
            }
        }

        cout << ans << endl;

    }

}
