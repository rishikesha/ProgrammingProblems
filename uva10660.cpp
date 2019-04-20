/* Rishikesh
 * UVA 10660 
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


int disthelper(int x, int y, int a) {
    return abs(x-a/5) + abs(y-a%5);
}

int dist(int x, int y, int p, vector<int> &a) {
    int tmp[5];
    transform(a.begin(), a.end(), tmp,
            [&x,&y](int u) {return disthelper(x,y,u);});
    return p * *min_element(tmp, tmp+5);
}


int main() {
    int ncases;
    cin >> ncases;
    while(ncases--) {
        int nareas;
        cin >> nareas;
        vector<int> x(nareas),y(nareas), population(nareas);
        for(int i = 0; i < nareas; i++) {
            cin >> x[i] >> y[i] >> population[i];
        }

        int64_t mindist=INT64_MAX;
        vector<int> answer(5), a(5);
        for(a[0] = 0; a[0] < 25; a[0]++) {
            for(a[1] = a[0]+1; a[1] < 25; a[1]++) {
                for(a[2] = a[1]+1; a[2] < 25; a[2]++) {
                    for(a[3] = a[2]+1; a[3] < 25; a[3]++) {
                        for(a[4] = a[3]+1; a[4] < 25; a[4]++) {
                            int64_t distcalc = 0;
                            for(int i = 0; i< nareas; i++) {
                                distcalc += dist(x[i], y[i],
                                        population[i], a);
                            }
                            if (distcalc < mindist) {
                                mindist=distcalc;
                                answer = a;
                            }
                        }
                    }
                }

            }
        }
        cout << answer[0] << " "
            << answer[1] << " "
            << answer[2] << " "
            << answer[3] << " "
            << answer[4] <<  "\n";
    }
}
