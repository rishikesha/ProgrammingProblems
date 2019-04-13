#include<iostream>
#include<cstdio>
using namespace std;

void getCoordinates(int sz, int p) {
    int x,y, i = 1;

    while ( i*i < p) i += 2;

    y = x = (sz+1)/2 + i/2;
    int dd = i*i - p; //how much i*i has gone past p
    int dx = 0, dy = -1, d = i - 1;

    while (dd > 0) { //simulate clockwise rotation by dd steps
        dd--;
        d--;
        y += dy;
        x += dx;
        if (d == 0) {
            d = i-1;
            int t = dx;
            dx = dy;
            dy = -t;
        }
    }
    printf("Line = %d, column = %d.\n", y, x);
}






int main() {
    int sz, p;
    while(true) {
        cin >> sz >> p;
        if (sz == 0)
            break;
        getCoordinates(sz,p);
    }
}
