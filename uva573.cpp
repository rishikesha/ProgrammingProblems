#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    while(true) {
        int H;
        double  U, D, F;
        cin >> H >> U >> D >> F;
        if (H == 0)
            break;

        F = U * F/100.0;
        int i = 1;
        double height = U;
        while(true) {
            if( height > H) {
                printf("success on day %d\n", i);
                break;
            } 
            if (height <= 0) {
                printf("failure on day %d\n", i);
                break;
            }

            height -= D;
            U -= F;
            if (U < 0)
                U=0;
            height += U;
            i++;
            cout << height << endl;
        }
    }
}
