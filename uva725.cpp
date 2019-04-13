#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;

bool check(int n, int m){
    unsigned int c = 0;
    if (n < 10000) {
        c |= 1;
    }
    while (n) {
        c |= (1 << (n%10));
        n = n /10;
    }
    while (m) {
        c |= (1 << (m%10));
        m = m /10;
    }

    return c == 1023;
}


void findsolutions(int m) {
    int M = 99999/m;
    int ct = 0;
    for (int i = 1234; i<= M; i++) {
        if(check(i,m*i)) {
            ct=1;
            if (i < 10000)
            printf("%d / 0%d = %d\n", (m*i), i, m);
            else
            printf("%d / %d = %d\n", (m*i), i, m);
        }
    }
    if(ct == 0) {
        printf("There are no solutions for %d.\n", m);
    }
}




int main() {
    int m;
    cin>>m;
    while (m !=0) {
        findsolutions(m);
        printf("\n");
        cin>>m;
    }

    return 0;

}
