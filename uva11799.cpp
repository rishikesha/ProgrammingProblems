#include<iostream>
#include<cstdio>
#include<climits>


using namespace std;

int main() {
    int T, n;
    cin >> T;

    for(int i = 0; i< T; i++) {
        int minspeed=INT_MIN, speed;
        
        cin >> n;

        for(int j = 0; j < n; j++) {
            cin >> speed;
            minspeed = max(speed, minspeed);
        }

        printf("Case %d: %d\n", i+1, minspeed);

    }
}
