/* Rishikesh
 * UVA 11242 Tour de France
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>

using namespace std;

int main() {
    int f,r;
    while(cin >> f, f) {
        cin >> r;
        vector<double> front, rear;
        vector<double> d;
        for(int i=0; i < f; i++) {
            double t; cin >> t;
            front.push_back(t);
        }
    
        for (int i = 0; i < r; i++) {
            double t; cin >> t;
            rear.push_back(t);
        }

        for(int i = 0; i < f; i++) {
            for (int j = 0; j < r; j++) {
                d.push_back(front[i]/rear[j]);
            }
        }

        sort(d.begin(), d.end());
        for(int i = 0; i< d.size() -1; i++) {
            d[i] = d[i+1]/d[i];
        }

        printf("%0.2f\n", *max_element(d.begin(),prev(d.end())));

    }
}
