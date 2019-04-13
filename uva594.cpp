#include<iostream>
#include<bitset>
#include<string>

using namespace std;

int main() {
    int n;
    string s;

    while (true) {
        getline(cin, s);
        if (s.length() == 0)
            break;

        /*
        int n = stoi(s);
        int a = 0;
        int c = 0;
        int mask = 255;

        c = mask & n;
        c = c << 24;
        a = a | c;

        n >>= 8;
        c = mask & n;
        c << 16;
        a = a | c;

        n >>= 8;
        c = mask & n;
        c << 8;
        a = a |c;

        n >>= 8;
        c = mask & n;
        a = a|c;
        cout << a << endl;
        */






        bitset<32> b(stoi(s));
        //cout << b << endl;
        for (int i = 0; i < 8; i++) {
            bool t = b[i];
            b[i] = b[24+i];
            b[24+i] = t;
        }
        for (int i = 0; i < 8; i++) {
            bool t = b[i+8];
            b[i+8] = b[16+i];
            b[16+i] = t;
        }

        //cout << b << endl;
        cout << s << " converts to " << static_cast<int>(b.to_ullong()) << endl;
    }

}
