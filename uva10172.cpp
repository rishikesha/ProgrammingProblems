/* Rishikesh
 * UVA 10172  
 * Read the problem statement very very carefully
 */
#include<iostream>
#include<queue>
#include<stack>
#include<string>
#include<sstream>
#include<algorithm>
#include<vector>

using namespace std;


int main() {
    string s;
    int ninputs;
    cin >> ninputs;
    while (ninputs--) {

        int N, S, Q;
        cin >> N >> S >> Q;
        vector<queue<int>> qB(N);
        int totalCargo = 0;

        for (int i = 0; i< N;i++) {
            int nC; cin >> nC;
            totalCargo += nC;
            for(int j = 0; j < nC; j++) {
                int tmp;
                cin >> tmp;
                qB[i].push(tmp-1);
            }
        }

        stack<int> truck;
        int currentPosition = 0;
        int timetaken=0;
        int timeToUnload = 1;
        int timeToLoad = 1;
        int travelTime = 2;
        int queueCapacity = Q;
        int truckCapacity = S;
        while(totalCargo) {
            //Unload
            while (not truck.empty()  and 
                    (truck.top() == currentPosition 
                     or qB[currentPosition].size() < queueCapacity)) {
                if (truck.top() == currentPosition) {
                    totalCargo--; //amount of work remaining is decreased
                }  else {
                    qB[currentPosition].push(truck.top());
                }

                truck.pop();
                timetaken += timeToUnload;
            }

            //Load
            while(truck.size()  < truckCapacity and
                    not qB[currentPosition].empty()) {
                truck.push(qB[currentPosition].front());
                qB[currentPosition].pop();
                timetaken += timeToLoad;
            }

            //Go to next position
            currentPosition = (currentPosition + 1) % N;
            if (totalCargo)
                timetaken += travelTime;
        }

        cout << timetaken << endl;


    }
}



