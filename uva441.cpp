#include<iostream>
using namespace std;


void process(int m){
    int a[m];
    for(int i = 0; i<m;i++) {
        cin >> a[i];
    }

    for(int i1 = 0; i1< m-5; i1++) {
        for(int i2 = i1+1; i2 < m-4;  i2++) {
            for(int i3 = i2+1; i3< m-3; i3++) {
                for(int i4 = i3+1; i4< m-2; i4++){
                    for(int i5 = i4+1; i5 < m-1; i5++) {
                        for(int i6 = i5 +1; i6 < m; i6++) {
                            cout << a[i1] << " "<< a[i2] << " "<< a[i3] << " "<< a[i4] << " "<< a[i5] << " "<< a[i6] << "\n";
                        }
                    }
                }
            }
        }
    }

    cout << "\n";

}



int main() {
    int m;
    while(cin>>m, m) {
        process(m);
    }


    return 0;

}
