#include<iostream>

using namespace std;

void split(uint32_t n) {
    uint32_t a,b,i;
    a=b=0;
    bool to_a = true;
    for (uint32_t j = 0; j < 32; j++) {
        i = 1 << j;
        if (n & i) {
            if (to_a) {
                a |= i;
                to_a = false;
            } else {
                b |= i;
                to_a=true;
            }
        }
    }
    cout << a << " " << b << "\n";
}



int main() {
    uint32_t n;
    while(cin >> n, n != 0) {
        split(n);
    }
}
