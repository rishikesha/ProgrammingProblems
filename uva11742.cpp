#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
#include<iostream>
#include<numeric>


using namespace std;

struct Restriction{
    int f1;
    int f2;
    int res;
    Restriction(int f1_, int f2_, int res_) : f1(f1_), f2(f2_), res(res_) {}
};

int main() {
    string s;
    while(getline(cin, s), s[0] !='0') {
        istringstream iss(s);
        int n,m;
        iss >> n >> m;

        vector<int> v(n); iota(v.begin(), v.end(), 0);

        vector<Restriction> restrictions;
        

        for(int i = 0; i < m; i++) {
            getline(cin, s); iss = istringstream(s);
            int f1, f2, res; iss >>  f1 >> f2 >> res;
            restrictions.push_back(Restriction(f1, f2, res));
        }

        int answer = 0 ;
        do {
            bool satisfied = true;
            for (auto rest : restrictions) {
                if (rest.res > 0)
                    satisfied = satisfied and  abs(v[rest.f1] - v[rest.f2]) <= rest.res;
                if (rest.res < 0)
                    satisfied = satisfied and abs(v[rest.f1] - v[rest.f2]) >= -rest.res;
            }
            if (satisfied)
                answer++;


        } while(next_permutation(v.begin(), v.end()));
        cout << answer << endl;

    }
}
