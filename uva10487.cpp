/* UVA 10487
 * This does gets WA. I have not been able to
 * come up with a test case which fails
 */
#include<iostream>
#include<cstdint>
#include<algorithm>

using namespace std;

int main() {
    long long  n;
    long long  caseno = 0;
    while(cin >> n, n) {
        printf("Case %d:\n", ++caseno);


        long long  a[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a+n);

        long long  nqueries;
        cin >> nqueries;
        while(nqueries--) {
            long long  num; cin >> num;
            long long  ans = 0;
            long long diff = INT64_MAX;
            for (int i = 0; i< n; i++) {
                for (int j = i+1; j < n; j++) {
                    if (a[i] != a[j] and diff > abs(num - (a[i] +a[j]))) {
                        ans = a[i] + a[j];
                        diff = abs(num - ans);
                    }

                }
            }
            printf("Closest sum to %lld is %lld.\n", num, ans);
        }
    }
}
