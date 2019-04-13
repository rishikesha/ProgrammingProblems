#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int i =0;

    while(i++ < n) {
        int a[3];
        cin >> a[0] >> a[1] >> a[2];
        sort(a,a+3);
        cout << "Case " << i << ": "<< a[1] << '\n';
    }
}
