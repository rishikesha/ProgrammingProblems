#include<iostream>
#include<cstdio>
using namespace std;


int main() {
    char c;
    string s;
    int ct=0;
    while((c=getchar()) != EOF) {
        if (c == '"') {
            if (ct) {
                ct--;
                s += "''";
            } else {
                ct++;
                s += "``";
            }
        } else {
            s += c;
        }
    }
    cout << s;
}
