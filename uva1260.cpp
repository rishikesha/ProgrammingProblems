#include<iostream>
#include<numeric>



using namespace std;

int main() {
    int ncases;
    cin >> ncases;
    while(ncases--) {
            int n;
            cin >> n;
            int a[n], b[n];
            for(int i = 0; i < n; i++) {
                cin >> a[i];
            }

            for(int i = 1; i < n; i++) {
                b[i-1] = 0;
                for(int j = 0; j < i; j++) {
                    if (a[j] <= a[i])
                        b[i-1]++;
                }
            }
            cout << accumulate(b, b+(n-1), 0) << endl;

    }
}
