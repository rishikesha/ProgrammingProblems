#include<iostream>

using namespace std;

int diff(int x, int y) {
    int a = y-x;
    if (a < 0)
        a += 40;
    return a;
}

int main() {
    int i,a,b,c;
    while(true) {
        cin >> i>> a >> b >> c ;
        if ( not (i or a or b or c))
            break;
        int ans= 0;
        ans = diff(a,i) + diff(a,b) + diff(c,b)+ 120;
        cout << ans * 9 <<"\n";
    }
}
