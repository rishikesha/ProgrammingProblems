#include<iostream>
#include<vector>
#include<numeric>

int lneigh[100100], rneigh[100100];

using namespace std;


int main() {
    int S,B;
    while (true) {
        cin >> S >> B;
        if (not (S or B)) {
            break;
        }

        iota(lneigh, lneigh+(S+2), -1);
        iota(rneigh, rneigh+(S+2), 1);

        for (int i = 0; i < B ;i++) {
            int l,r ;
            cin >> l >> r;

            if (l > 0) {
                l = lneigh[l];
            }

            if (r <= S) {
                r = rneigh[r];
            } 

            lneigh[r] = l;
            rneigh[l] = r;


            if (l <= 0)
                printf("* ");
            else
                printf("%d ",l);

            if (r > S)
                printf("*\n");
            else
                printf("%d\n",r);

        }

        printf("-\n");

    }

}
