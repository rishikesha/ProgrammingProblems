#include<iostream>

using namespace std;


void process() {
    int A,B,C;
    cin >> A >> B >> C;
    int x, y, z;

    for(x = -100; x<101; x++) {
        for(y = x+1; y< 101; y++) {
            z = A-x -y;
            if ( x != z and y != z and x*y*z == B and x*x +y*y+z*z == C) {
                cout << x << " " << y << " "<< z << "\n";
                return;
            }
        }
    }
    cout << "No solution.\n";
}

int main() {
    int m;
    cin >> m;
    while(m>0){
        process();
        m--;
    }

    return 0;
}
