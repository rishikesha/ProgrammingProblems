/* Rishikesh
 *  UVA 1203
 */

#include<queue>
#include<iostream>
#include<string>
#include<vector>
#include<functional>

using namespace std;

struct Query {
    int reportingtime;
    int qnum;
    int period;
    Query (int nrt, int qn, int pd) :
        reportingtime(nrt), qnum(qn), period(pd) {}
};

int main() {
    function<bool(Query, Query)> compare = [](Query a, Query b) {
        return make_pair(a.reportingtime, a.qnum) > make_pair(b.reportingtime, b.qnum);
    };
    priority_queue<Query,vector<Query>, decltype(compare)> pq(compare);

    string s;
    while (cin >> s, s != "#") {
        int report, period, qnum;
        cin >> qnum >> period;
        pq.push(Query(period, qnum, period));
    }

    int nepoch; cin >> nepoch;
    while (nepoch--) {
        Query t = pq.top();
        pq.pop();
        cout << t.qnum <<  endl;
        pq.push(Query(t.reportingtime + t.period, t.qnum, t.period));
    }


}
