/* Rishikesh
 * UVA 11057 Exact Sum
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

int main() {
    string s;
    while(getline(cin, s), s.length()) {
        int n, budget;
        n = stoi(s);
        vector<int> prices(n);

        istringstream iss;
        getline(cin, s); iss = istringstream(s);
        for(int i = 0; i < n; i++) {
            iss >> prices[i];
        }
        getline(cin, s); iss = istringstream(s);
        iss >> budget;

        sort(prices.begin(), prices.end());
        int first = 0, last = prices.size() -1;
        int book1, book2;
        while(first <  last) {
            int currsum = prices[first] + prices[last];
            if (currsum < budget)
                first++;
            else if (currsum > budget)
                last--;
            else {
                book1 = prices[first];
                book2 = prices[last];
                first++; last--;
            }
        }
        cout << "Peter should buy books whose prices are " << book1
            << " and " <<book2 << ".\n\n";

        getline(cin, s);
    }
}
