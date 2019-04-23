/* Rishikesh
 * UVA 624 CD
 */
#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<iomanip>
#include<cstdint>
#include<numeric>

using namespace std;

typedef tuple<int, int, int> tiii;



int main()  {
    string s;
    while(getline(cin,s), s.length()) {
        istringstream iss(s);
        int n; iss >> n;

        int t; iss >> t;
        vector<int> numbers(t);
        for(int i = 0; i< t; i++) {
            iss >> numbers[i];
        }


        //below is dfs with pruning
        //I should have used a struct instead of tuple
        stack<tiii> st;
        st.push(tiii(0,0,0));
        st.push(tiii(0,numbers[0],1));
        int bestlength =0;
        int bestset  = 0;
        while (not st.empty()) {
            tiii t = st.top();
            int i = get<0>(t);
            int l = get<1>(t);
            int mask = get<2>(t);
            if (l > bestlength and l <= n) {
                bestlength = l;
                bestset = mask;
            }

            st.pop();

            if (i < numbers.size() - 1 and l < n) {
                st.push(tiii(i+1, l, mask));
                st.push(tiii(i+1, l+numbers[i+1], mask | (1 << (i+1))));
            }
        }

        int i = 0;
        while(bestset) {
            if (1 & bestset) {
                cout << numbers[i] << " ";
            }
            bestset = bestset >> 1;
            i++;
        }
        cout << "sum:"<<bestlength << endl;
    }
}
