/* Rishikesh
 * UVA 00119 Greed Gift Givers
 * I used udebug to solve this problem. This is a problem from the 90s 
 * and it
 * has all the kinks which have since been ironed out. Moreover
 * STL and java libraries have made this much easier that it would have been
 * at the time.
 */

#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<map>
#include<numeric>
#include<algorithm>

using namespace std;

int main() {
#ifdef DEBUGUVA
    freopen("test", "r", stdin);
    cerr << "This is DEBUG\n";
#endif
    int N;

    cin >> N;
    while(true) {
        map<string, int> bal;
        vector<string> names(N);
        for(int i = 0; i < N; i++) {
            cin >> names[i];
            bal[names[i]] = 0;
        }

        for (int i = 0; i < N; i++) {
            string name;
            int money, n;
            cin >> name;
            cin >> money >> n;

            if (n == 0) {
                //bal[name] += money;
                continue;
            }

            int portion = money/n;
            bal[name] = bal[name] - money + money % n; // We keep the what is not
                                                      // distributed

            for (int j = 0; j < n; j++) {
                cin >> name;
                bal[name] += portion;
            }
        }

        for(int i = 0; i < N; i++) {
            cout << names[i] << " " << bal[names[i]] << endl;
        }

        cin >> N;
        if (cin.eof())
            break;
        else
            cout << "\n";


    }


}
