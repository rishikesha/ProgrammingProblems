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

int dist(int x, int y, int p, int a1, int a2, int a3, int a4, int a5) {
    return p * min(disthelper(x,y,a1), 
            min(disthelper(x,y,a2),
                min(disthelper(x,y,a3),
                    min(disthelper(x,y,a4),
                        disthelper(x,y,a5)))));
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
        vector<int> answer(5);
        for(int a1 = 0; a1 < 25; a1++) {
            for(int a2 = a1+1; a2 < 25; a2++) {
                for(int a3 = a2+1; a3 < 25; a3++) {
                    for(int a4 = a3+1; a4 < 25; a4++) {
                        for(int a5 = a4+1; a5 < 25; a5++) {
                            int64_t distcalc = 0;
                            for(int i = 0; i< nareas; i++) {
                                distcalc += dist(x[i], y[i],
                                        population[i], a1,a2,a3,a4,a5);
                            }
                            if (distcalc < mindist) {
                                mindist=distcalc;
                                answer = {a1,a2,a3,a4,a5};
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
