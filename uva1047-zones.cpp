/* Rishikesh
 * UVA 1047 Zones
 * Heavy bit manipulation so harder to understand
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
#include<bitset>

using namespace std;

int countBits(int n) { //Counts the number or 1's in n
    int ans = 0;
    while(n) {
        n -= (n & (-n));
        ans++;
    }
    return ans;
}



int main() {
    int n, m;
    int caseno=1;
    while(cin >> n, n>0) {
        cin >> m;
        
        int population[1<<n]{0};

        for(int i = 0; i < n; i++) {
            int t; cin >> t;
            int ind = 1 << i;
            for(int j = ind; j < (1<<n); j++) {
                if ((j & ind) == ind)
                    population[j] += t;
            }
        }

        int n1; cin >> n1;
        int prevcomb = 1, prevsign=-1;
        for (int i = 0; i < n1 ; i++) {
            int ind = 0;
            int n2; cin >> n2;
            for (int k = 0; k < n2; k++) {
                int t; cin >> t; t--; // O indexing of 
                ind |= (1 << t);
            }
            int val; cin >> val;
            for(int j = 0; j < (1<<n); j++) {
                if ((j & ind) == ind) {
                    if (n2 & 1)
                        population[j] += val;
                    else
                        population[j] -= val;
                }
            }
        }



        int highestServed = 0;
        int thebestset = 0;
        for(int i = 0; i < (1 << n); i++) {
            int c = countBits(i);
            if (c ==m and population[i] > highestServed) {
                highestServed = population[i];
                thebestset = i;
            }
        }
        cout << "Case number "<< caseno++ << "\n";
        cout << "Number of Customers: ";
        cout << highestServed << endl;
        cout << "Locations recommended:";
        for (int i = 0; i < n; i++) {
            if ((1<<i) & thebestset)
                cout << " " << i+1;
        }
        cout <<"\n\n";

    }
}
