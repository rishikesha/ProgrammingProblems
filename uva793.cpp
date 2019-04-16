/*
 * Rishikesh
 * UVA 793
 */
#include<vector>
#include<iostream>
#include<set>
#include<algorithm>
#include<numeric>
#include<string>
#include<sstream>
#include<set>

using namespace std;

class UnionFind {
    private:
        const int size;
        vector<int> parent;
        vector<int> rank;
        
    public:
        UnionFind(int sz) : size(sz) {
            parent.resize(sz);
            rank.resize(sz);
            iota(parent.begin(), parent.end(), 0);
        }

        void un(int i, int j) {
            int pi = find(i);
            int pj = find(j);
            if (rank[pj] < rank [pi])
                swap(pi, pj);
            parent[pi] = pj;
            if (rank[pi] == rank[pj]) 
                rank[pj]++;
        }

        int find(int i) {
            if (parent[i] == i)
                return i;
            else {
                parent[i] = find(parent[i]);
                return parent[i];
            }
        }

};


int main() {
    int ncases;
    string s;
    getline(cin, s);
    istringstream iss;
    ncases = stoi(s);
    getline(cin,s);
    while(ncases--) {
        getline(cin,s);

        int ncomputers=stoi(s);
        int successful=0, unsuccessful=0;
        auto uf = UnionFind(ncomputers);

        while(getline(cin,s), s.length()) {

            iss = istringstream(s);
            char cq; int c1, c2;
            iss >> cq; 
            iss >> c1 >> c2;
            c1--; c2--;

            if (cq == 'c') {
                uf.un(c1, c2);
            } else {
                if (uf.find(c1) == uf.find(c2))
                    successful++;
                else
                    unsuccessful++;
            }
        }
        cout  << successful << "," << unsuccessful <<"\n";
        if (ncases)
            cout << "\n";
    }
}
