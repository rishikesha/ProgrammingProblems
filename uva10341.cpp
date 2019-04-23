/* Rishikesh
 * UVA 10341
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
#include<cmath>

using namespace std;



double func(vector<int>& v, double x) {
    return v[0] * exp(-x) + v[1] * sin(x) + v[2]*cos(x) + v[3] * tan(x) + v[4] * x * x + v[5];
}



int main() {
    string s;
    while(getline(cin, s), s.length() > 5) {
        istringstream iss(s);
        vector<int> v(6);
        for(int i = 0; i < 6; i++) iss >> v[i];

        double left = 0, right = 1;
        double lf=func(v,left), rf=func(v,right), mid, mf;
        

        if (lf * rf > 0) {
            printf("No solution\n");
        } else {
            do {
                mid = (left + right)/2;
                mf = func(v, mid);
                if (mf * lf > 0)  {
                    left = mid;
                    lf = mf;
                }
                else {
                    right = mid;
                    rf  =mf;

                }
            } while (abs(mf) > 1e-9);
            int ans = round(10000*mid);
            printf("%d.%04d\n", ans/10000,ans%10000);
        }
    }
}
