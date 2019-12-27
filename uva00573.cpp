/* Rishikesh
 * UVA 00573 The Snail
 * Look at the table about how the snail moves. It has
 * to be followed diligently if the test is to be passed.
 */

#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<map>
#include<numeric>
#include<algorithm>

using namespace std;

int main() {
#ifdef DEBUGUVA
    freopen("test", "r", stdin);
    cerr << "This is DEBUG\n";
#endif
    double H, U, D, F;
    while (cin >> H >> U >> D >> F, H > 0) {
        double reduction = F/100 * U;
        int d = 1;
        double h = U;
        bool success = false;

        while(h > 0 and h <= H) {
            h -= D;
            if (h < 0)
                break;
            U = max(0.0 , U - reduction);
            d += 1;
            h += U;
        }

        if (success) {
            cout << "success on day " << d << endl;
        } else {
            cout << "failure on day " << d << endl;
        }

    }
}
