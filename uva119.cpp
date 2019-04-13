#include<cstdio>
#include<iostream>
#include<map>
#include<string>
#include<vector>

using namespace std;


int main() {

    while(true) {
        int n;
        string s;
        vector<string> names;
        map<string, int> given;

        if(scanf("%d", &n) == EOF)
            return 0;

        for(int i = 0; i< n; i++) {
            cin >> s;
            names.push_back(s);
            given[s] = 0;
        }

        for (int i = 0; i < n; i++) {
            int a,f;
            cin >> s;
            cin >> a;
            cin >> f;
            if (f != 0) 
                a = (a/f)*f;
            given[s] -= a;
            for (int j = 0; j< f; j++) {
                cin >> s;
                given[s] += a/f;
            }
        }

        for (int i = 0; i<n; i++) {
            cout << names[i] << " " << given[names[i]] << "\n";
        }

        cout << "\n";
    }


}
