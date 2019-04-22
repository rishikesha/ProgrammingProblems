/* Rishikesh
 * UVA 11935
 * Through the Desert
 * This problem is classified as binary search problem in
 * Halim's CP3 book. It can be done in one simulation of the race.
 * You have to keep track of fuel used until one reaches a gas station
 * or the goal. 
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
    bool done = false;
    vector<double> fuelconsumed(1); //Keeps track of fuel needed till the next gas station of the goal
    int fuelconsumption;
    int leaks = 0, prevmarker = 0;
    int when, quantity; string what;
    while (true) {
        getline(cin, s);
        auto iss = istringstream(s);
        iss >> when >> what;
        if (what == "Goal") {
            if (when > 0) {
                fuelconsumed.back() += double(when - prevmarker)*fuelconsumption/100.0 + 
                    (when - prevmarker) * leaks;
            }
            printf("%0.3f\n", *max_element(fuelconsumed.begin(), fuelconsumed.end()));
            fuelconsumed.resize(1); fuelconsumed = {0};
            prevmarker = 0;
            fuelconsumption = 0;
            leaks = 0;
        } else if (what == "Fuel") {
            if (when > 0) {
                fuelconsumed.back() += double(when - prevmarker)*fuelconsumption/100.0 + 
                    (when - prevmarker) * leaks;
                prevmarker = when;

            }
            iss >> what;
            iss >> fuelconsumption;
            prevmarker = when;
            if (fuelconsumption == 0)
                break;
        } else if (what == "Leak") {
            fuelconsumed.back() += double(when - prevmarker)*fuelconsumption/100.0 + 
                (when - prevmarker) * leaks;
            prevmarker = when;
            leaks++;
        } else if ( what == "Mechanic") {
            fuelconsumed.back() += double(when - prevmarker)*fuelconsumption/100.0 + 
                (when - prevmarker) * leaks;
            prevmarker = when;
            leaks = 0;
        } else if (what == "Gas" ) {
            fuelconsumed.back() += double(when - prevmarker)*fuelconsumption/100.0 + 
                (when - prevmarker) * leaks;
            prevmarker = when;
            fuelconsumed.push_back(0);

        }

    }
}
