#include<string>
#include<sstream>
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;
char colors[]{'B', 'C', 'G'};

int main() {
    string s;
    while (getline(cin, s), s.length()) {
        auto iss = istringstream(s);
        int bottles[9];
        for(int i = 0; i< 9; i++) iss>>bottles[i];
        // Unfortunately the input is BGC where as sorted order is BCG
        for(int i = 0; i < 3; i++) swap(bottles[3*i+1], bottles[3*i+2]);
        int sum = accumulate(bottles, bottles+9, 0);
        vector<int> answer;
        unsigned int minsum = INT32_MAX;
        vector<int> v{0,1,2};
        do {
            int a;
            a=bottles[v[0]] + bottles[3+v[1]]  + bottles[6+v[2]];
            if (sum - a < minsum) {
                minsum = sum -a;
                answer = v;
            }
        } while (next_permutation(v.begin(), v.end()));
        for(int i =0; i< 3;i++)
            cout << colors[answer[i]];

        cout << " " << minsum <<endl;


    }
}
