/*
 * Rishikesh
 * UVA 11503
 */
#include<vector>
#include<iostream>
#include<set>
#include<algorithm>
#include<numeric>
#include<string>
#include<sstream>
#include<map>

using namespace std;

class UnionFind {
    private:
        const int size;
        vector<int> parent;
        vector<int> rank;
        vector<int> count;
        
    public:
        UnionFind(int sz) : size(sz) {
            parent.resize(sz);
            rank.resize(sz);
            count.resize(sz);
            iota(parent.begin(), parent.end(), 0);
            fill(count.begin(), count.end(), 1);
        }

        void un(int i, int j) {
            int pi = find(i); int pj = find(j);
            if (pi == pj)
                return;
            if (rank[pj] < rank [pi])
                swap(pi, pj);
            parent[pi] = pj;
            if (rank[pi] == rank[pj]) 
                rank[pj]++;
            count[pj] += count[pi];
        }

        int find(int i) {
            if (parent[i] == i)
                return i;
            else {
                parent[i] = find(parent[i]);
                return parent[i];
            }
        }

        int getcount(int i) {
            return count[find(i)];
        }

};


int main() {
    int ncases;
    string s;
    getline(cin, s);
    istringstream iss;
    ncases = stoi(s);
    while(ncases--) {
        UnionFind ufset(100001);
        getline(cin,s);
        int nedges= stoi(s);
        vector<pair<string, string>> edges;
        map<string, int> nametonum;
        int serialno = 1;
        for (int i = 0 ; i < nedges; i++) {
            getline(cin, s); iss = istringstream(s);
            string n1, n2;
            iss >> n1 >> n2;

            if (nametonum.find(n1) == nametonum.end())
                nametonum[n1] = serialno++;
            if (nametonum.find(n2) == nametonum.end())
                nametonum[n2] = serialno++;

            ufset.un(nametonum[n1], nametonum[n2]);
            cout << ufset.getcount(nametonum[n1])<< endl;
        }
    }
}
