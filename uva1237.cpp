#include<iostream>
#include<vector>
#include<string>
#include<sstream>


using namespace std;

int main() {
    int ncases;
    cin >> ncases;
    while(ncases--) {
        int nmodels;
        cin >> nmodels;

        vector<string> model(nmodels);
        vector<int> low(nmodels), high(nmodels);
        for(int i = 0 ; i < nmodels; i++) {
            cin >> model[i] >> low[i] >> high[i];
        }

        int nqueries;
        cin >> nqueries;
        while(nqueries--) {
            int price;
            cin >> price;
            string s="";
            for (int i = 0; i < nmodels; i++) {
                if (low[i] <= price and high[i] >= price)
                    if (s == "")
                        s = model[i];
                    else
                        s = "UNDETERMINED";
            }
            if (s == "") s = "UNDETERMINED";
            cout << s <<"\n";
        }

        if (ncases)
            cout << "\n";
    }
}
