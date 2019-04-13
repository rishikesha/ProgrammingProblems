#include<string>
#include<vector>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<numeric>

using namespace std;

int main() {
    while(true) {
        int nrow;
        string s;
        scanf("%d\n", &nrow);
        if (nrow == 0)
            break;

        vector<int> v;

        for (int i = 0; i< nrow; i++) {
            getline(cin, s);
            v.push_back(std::count(s.begin(), s.end(), ' '));
        }
        int m = *std::min_element(v.begin(), v.end());
        cout << accumulate(v.begin(), v.end(), 0) - m * v.size()  << '\n';

    }
}
