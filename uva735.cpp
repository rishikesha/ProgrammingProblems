#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<iomanip>
#include<cstdint>
#include<numeric>

using namespace std;

void process(int n, set<int>& scores) {
    set<vector<int>> comb;
    int perm = 0;
    if (n <=  180) {
        for (int s1 : scores) {
            if (s1 > n)
                break;
            for (int s2 : scores) {
                if (s1+s2 > n)
                    break;
                for (int s3 : scores) {
                    if (s1+s2+s3 == n) {
                        if (s1+s2+s3 > n)
                            break;
                        perm++;
                        vector<int> v{s1,s2,s3};
                        sort(v.begin(), v.end());
                        comb.insert(v);
                    }
                }
            }
        }
    }
    if (perm) {
        printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", n, comb.size());
        printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", n, perm);
    } else {
        printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n",  n);
    }
}


int main() {
    int inp;
    set<int> scores;
    scores.insert(50);
    scores.insert(0);
    for(int i = 1; i<=20; i++) {
        scores.insert(i);
        scores.insert(2*i);
        scores.insert(3*i);
    }

    while(cin >> inp) {
        if (inp>0) {
            process(inp, scores);
            printf("**********************************************************************\n");
        } else {
            printf("END OF OUTPUT\n");
            break;
        }
    }
}
