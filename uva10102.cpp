/* Rishikesh
 * uva10102 I get runtime error in the online judge
 * but I have not been able to replicate it.
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

using namespace std;



int main() {
    string s;
    while(getline(cin, s), s.length()){
        int m = stoi(s);
        vector<string> mat;
        for (int i = 0; i< m; i++) {
            getline(cin, s);
            mat.push_back(s);
        }

        int mindist = 0;
        for (int i1 = 0; i1 < m; i1++) {
            for (int i2 = 0; i2 < m; i2++) {
                if (mat[i1][i2] != '1')
                    continue;
                int localmindist = 999999999;
                for (int i3 = 0; i3 < m; i3++) {
                    for (int i4 = 0; i4 < m; i4++) {
                        if (mat[i3][i4] == '3')
                            localmindist = min(localmindist, abs(i1 -i3) + abs(i2 - i4));
                    }
                }
                mindist=max(mindist, localmindist);
            }
        }
        cout << mindist << endl;

    }

}
