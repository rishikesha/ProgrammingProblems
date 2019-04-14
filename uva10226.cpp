/* Rishikesh
 * UVA 10226
 */

#include<string>
#include<map>
#include<iostream>

using namespace std;

int main() {
    string s;
    int n;
    map<string, int> m;

    cout.precision(4);
    getline(cin, s);
    n = stoi(s);
    getline(cin, s);
    while(n--) {
        m.clear();
        int count =0;
        while(true) {
            getline(cin,s);
            if  (s.length() == 0)
                break;
            count++;

            m[s] += 1;
        }

        for(auto it=m.begin(); it != m.end(); it++) {
            printf("%s %0.4f\n",it->first.c_str(), double(it->second)/count * 100);
        }

        if(n)
        cout << "\n";
    }
}
