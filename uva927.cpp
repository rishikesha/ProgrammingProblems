/* UVA 927 Integer sequences from addition of terms
 * Rishikesh
 */


#include<iostream>
#include<cstdint>

using namespace std;

int findN(int d, int k) {
    int guess = 0;
    while ((guess * (guess +1)/2) * d < k) //could do in O(log(k)) but this will do here
        guess++;

    return guess;
}


int main() {
    int ncases;
    cin >> ncases;
    while(ncases--) {
        int64_t deg;
        cin >> deg;
        int64_t c[deg+1];
        for (int i = deg; i >= 0; i--) {
            cin >> c[i];
        }
        int64_t d, k;
        cin >> d >>k;
        int64_t n = findN(d,k);
        int64_t answer = 0;
        for(int i = 0; i <= deg; i++) {
            answer = answer * n + c[i];
        }
        cout << answer << endl;
    }
}
