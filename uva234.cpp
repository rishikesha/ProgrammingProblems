/* Rishikesh
 * UVA 234 Switching Channels
 *  The answer does not match the sample
 *  but from my understanding of the problem
 *  the sample answer is wrong.
 *  This solution does get accepted.
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
#include<climits>

using namespace std;
typedef long long ll;

pair<ll, ll> 
calculatePenalty(vector<int> &time, vector<pair<int,int>>& penalty){
    ll pen=0;
    ll error = 0;
    vector<ll> tmp(time.size());
    partial_sum(time.begin(), time.end(), tmp.begin());
    for(auto p: penalty) {
        ll t=LLONG_MAX;
        for (int i = 0; i < tmp.size(); i++) {
            t = min(abs(tmp[i] - p.second), t);
        }
        error += t;
        t *= (1 << (50 - 10*p.first)); // factor of 1024 for each higher priority
        pen += t;
    }
    return make_pair(pen, error);

}

int main() {
    int p;
    int caseno=1;
    while (cin >> p, p>0) {
        vector<int> time(p);
        for(int i=0; i<p; i++) {
            cin >> time[i];
        }
        int a;
        cin >> a;
        vector<pair<int,int>> penalty;
        for(int i = 0 ; i < a; i++) {
            int t1, t2;
            cin >> t1 >> t2;
            penalty.push_back(make_pair(t1, t2));
        }


        vector<int> test {15, 13, 10, 18, 25,33};
        calculatePenalty(test, penalty);


        ll minpenalty = LLONG_MAX;
        ll error = 0;
        vector<int> answer;
        sort(time.begin(), time.end());
        do {
            pair<ll, ll> pe = calculatePenalty(time, penalty);
            if (pe.first < minpenalty) {
                minpenalty = pe.first;
                answer = time;
                error = pe.second;
            }
        } while(next_permutation(time.begin(), time.end()));

        cout << "Data set " << caseno++ << "\n";
        cout << "  Order: ";
        cout << answer[0];
        for (int i = 1; i < p; i++)
            cout << " " << answer[i];
        cout << "\n";
        cout << "  Error: " << error << "\n";
    }
}
