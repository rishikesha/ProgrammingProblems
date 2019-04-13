#include<iostream>
#include<bitset>
#include<vector>

using namespace std;

typedef bitset<1000100> bs;

bool hasConflict(int n, int m, vector<int>& sf, vector<int>& ef, vector<int>& sr, vector<int>& er, vector<int>& tr) {
    bs b(0);
    for (size_t i = 0; i < n; i++) {
        for(size_t j = sf[i]; j < ef[i]; j++) {
            if(b.test(j))
                return true;
            else {
                b.set(j);
            }
        }
    }

    for(size_t i = 0; i < m; i++) {
        for(size_t j = sr[i]; j < er[i]; j++) {
            for (size_t k = 0; k*tr[i] +j < 1000000; k++) {
                if (b.test(k*tr[i] + j))
                    return true;
                else
                    b.set(k*tr[i] + j);

            }
        }
    }

    return false;
}



int main() {
    int n, m, t;
    while (cin >> n >> m, n!=0 or m!=0) {
        vector<int> sf(n), ef(n), sr(m), er(m), tr(m);
        for(int i = 0; i < n; i++) {
            cin >> sf[i] >> ef[i];
        }

        for(int i = 0; i < m; i++) {
            cin >> sr[i] >> er[i] >> tr[i];
        }

        if (hasConflict(n,m,sf,ef,sr,er,tr)) {
            cout << "CONFLICT\n";
        } else {
            cout << "NO CONFLICT\n";
        }
    }
}
