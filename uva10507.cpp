#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<sstream>
#include<map>



using namespace std;


int main() {
    string s;
    istringstream iss;
    while(getline(cin, s), s.length()) {
        int nslept, nedges;
        nslept = stoi(s);
        getline(cin, s);
        nedges = stoi(s);
        getline(cin, s);
        set<char> awake;
        for (char c : s) {
            awake.insert(c);
        }

        map<char, vector<char>> graph;
        for(int i=0; i < nedges; i++) {
            getline(cin, s);
            graph[s[0]].push_back(s[1]);
            graph[s[1]].push_back(s[0]);
        }


        int currawake = awake.size();
        int prevawake;
        int nyears=0;
        do {
            vector<char> newawake;
            prevawake = currawake;
            for (auto v : graph) {
                if (awake.count(v.first)) {
                    continue;
                }
                int nawake = 0;
                for (char c : v.second) {
                    if (awake.count(c)) {
                        nawake++;
                    }
                }
                if (nawake > 2)
                    newawake.push_back(v.first);
            }
            for (auto c : newawake)
                awake.insert(c);

            currawake = awake.size();
            nyears++;
        } while (prevawake != currawake);

        if (currawake == nslept) {
            printf("WAKE UP IN, %d, YEARS\n", nyears-1);
        } else {
            printf("THIS BRAIN NEVER WAKES UP\n");
        }

        getline(cin, s);

    }

}
