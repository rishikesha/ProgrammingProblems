#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>

using namespace std;

int main() {
    int p,n;
    string s;
    istringstream iss;
    int c;
    while (getline(cin,s), s.length()) {
        iss= istringstream(s);
        iss >> n;
        vector<int> v;
        v.clear();
        v.resize(n-1);
        int a1, a2;
        iss >> a2;

        for (int i = 0; i < n-1; i++) {
            iss >> a1;
            int absdiff = abs(a1-a2);
            if (absdiff >0 and absdiff < n) {
                v[absdiff-1] = true;
            }
            a2 = a1;
        }




        if (all_of(v.begin(), v.end(), [](bool x) {return x;})){
            cout << "Jolly\n";
        } else {
            cout << "Not jolly\n";
        }
    }
}
