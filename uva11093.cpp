#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;
int p[100005], q[100005];

int main() {
    int T;
    cin >> T;

    for(int ca = 0; ca < T; ca++ ) {
        int N, pp, qq;
        int b = pp = qq = 0;
        cin >> N;

        for(int i=0; i<N; i++)
            cin >> p[i];
        for(int i=0; i<N; i++)
            cin >> q[i];

        for (int i = 0; i< 2*N ; i++) {
            pp += p[i%N];
            qq += q[i%N];
            if (pp < qq) {
                pp = 0;
                qq = 0;
                b = i + 1;
            }

            if (b >= N) {
                break;
            }
        }

        if (b >= N) {
            printf("Case %d: Not possible\n", ca+1);
        } else {
            printf("Case %d: Possible from station %d\n", ca+1, b+1);
        }






    }

}


