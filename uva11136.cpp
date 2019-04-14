#include<iostream>
#include<set>
#include<string>
#include<sstream>
#include<cstdint>

using namespace std;

int main() {
    int n;
    while(cin >> n, n > 0) {
        multiset<int> ms;

        uint64_t amount=0; //needed for WA resulting from int overflow
        while(n--) {
            int numBills, tmp;
            cin >> numBills;
            while(numBills--) {
                cin >> tmp;
                ms.insert(tmp);
            }

            //Can store the iterators in a variable, erase does not invalidate
            //other iterators
            amount += *(prev(ms.end())) - *ms.begin();

            ms.erase(ms.begin()); ms.erase(prev(ms.end()));

        }
        cout << amount << endl;
    }

}

