/* Rishikesh
 * UVA 534 prime ring
 * The switch version of isPrime makes the program run
 * 5 times faster. It might be better to replace set
 * with bitset or just an integer here.
 */
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
#include<stack>
#include<queue>
#include<list>
#include<deque>
#include<bitset>

using namespace std;

bool isPrime(int n) {
    switch(n) {
        case 2:
        case 3:
        case 5:
        case 7:
        case 11:
        case 13:
        case 17:
        case 19:
        case 23:
        case 29:
        case 31:
        case 37:
        case 43:
        case 41:
            return true;
        default: return false;
    }
}
/*
   bool isPrime(int n) {
   set<int> primes{2,3,5,7,11,13,17,19,23,29,31,37,43,41};
   return primes.count(n);
   }*/


vector<int> v;
vector<vector<int>> answer;

void fill(int m, int n, set<int> s) {
    if (m == n) {
        answer.push_back(v);
    } else {
        for (int x : s) {
            if (isPrime(v[m] + x)) {
                if (m < n-2) {
                    v[m+1] = x;
                    set<int> s2 = s; s2.erase(x);
                    fill(m+1, n,s2);
                } else {
                    if (isPrime(x+1)) {
                        v[m+1] = x;
                        answer.push_back(v);
                    }
                }
            }
        }
    }

}

int main() {
    string s;
    int caseno = 1;
    getline(cin, s);
    while(s.length()) {
        cout << "Case " << caseno++ <<":\n";
        answer.clear();
        int n = stoi(s);
        set<int> ss;
        for (int i = 2; i<=n; i++) ss.insert(i);
        v.resize(n);
        v[0] = 1;
        fill(0,n,ss);
        for (auto xx: answer) {
            cout << xx[0];
            for (int i =1; i< xx.size(); i++) cout<< " " << xx[i];
            cout << "\n";
        }
        getline(cin, s);
        if(s.length()) 
            cout << "\n";
    }
}
