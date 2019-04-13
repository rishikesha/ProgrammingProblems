#include<iostream>
#include<cstdio>
#include<climits>
using namespace std;


int main() {
    int N, B, H, W;
    int price, available;


    while (true) {
        int minprice = INT_MAX;


        if (scanf("%d %d %d %d", &N, &B, &H, &W) == EOF)
            return 0;

        for(int i = 0; i< H; i++) {
            cin >> price;
            for(int j =0; j < W; j++) {
                cin >> available;
                if (available >= N and N*price <= B) {
                    minprice = min(minprice, N*price);
                }
            }
        }

        if (minprice == INT_MAX) {
            cout << "stay home\n";
        } else {
            cout << minprice <<"\n";
        }
    }


}

