#include<iostream>
#include<vector>
#include<bitset>
#include<string>
#include<algorithm>

using namespace std;


int main() {
    string s;
    int n;
    getline(cin , s);
    n = stoi(s);
    while (n--) {
        bitset<26> edgeAttached;
        int nedges = 0;
        while(getline(cin, s), s.length() > 0 and s[0] != '*') {
            edgeAttached.set(s[1]-'A');
            edgeAttached.set(s[3]-'A');
            nedges++;
        }
        getline(cin, s);
        int nvert = 1 + count_if(s.begin(), s.end(), [](char c) { return c ==',';});
        int ncomponents = nvert - nedges;
        int nacorns = nvert  - edgeAttached.count();
        printf("There are %d tree(s) and %d acorn(s).\n", ncomponents - nacorns, nacorns);

    }
}
