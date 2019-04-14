#include<set>
#include<iostream>
#include<cstdint>

using namespace std;

int main() {
    int jackN, jillN;
    while (cin >> jackN >> jillN, jackN or jillN) {
        set<int>  jackcd;
        int tmp;
        for(int i = 0; i < jackN; i++) {
            cin >> tmp;
            jackcd.insert(tmp);
        }

        for(int i = 0; i < jillN; i++) {
            cin >> tmp;
            jackcd.erase(tmp);
        }
        cout << jackN - jackcd.size() << endl;


    }
}
