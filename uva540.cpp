#include<queue>
#include<iostream>
#include<vector>
#include<map>
#include<sstream>
#include<list>

using namespace std;

class TeamQueue {
    int team[1000001];
    queue<int> q[1001];
    int numteams=0;
    list<int> tq;


    public:
    void enqueue(int m) {
        int t = team[m];
        q[t].push(m);
        tq.push_back(t);
    }

    int dequeue() {
        int t = tq.front();
        int ret = q[t].front();
        q[t].pop();
        if (q[t].empty()) {
            for(auto it = tq.begin(); it != tq.end(); ) {
                auto p = it++; // it has to incremented before deletion
                if (*(p) == t) {
                    tq.erase(p);
                }
            }
        }

        return ret;
    }

    void readTeam(string s) {
        int t, m;
        istringstream iss(s);
        iss >> t;
        for(int i = 0; i < t; i++) {
            iss >> m;
            team[m] = numteams ;
        }
        numteams++;
    }

};


int main() {
    int n, i = 0;
    string s;
    istringstream iss;
    while (getline(cin,s), s != "0") {
        i++;
        printf("Scenario #%d\n", i);
        TeamQueue tq;
        n = stoi(s);

        while(n-- > 0) {
            getline(cin, s);
            tq.readTeam(s);
        }

        while(getline(cin, s), s != "STOP") {
            iss = istringstream(s);
            string command; iss >> command;
            if (command == "DEQUEUE")
                cout << tq.dequeue() << endl;
            else if (command == "ENQUEUE") {
                int m; iss >> m;
                tq.enqueue(m);
            }
        }

        
        printf("\n");
    }
}

