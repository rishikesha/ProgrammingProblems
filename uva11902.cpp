
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

void dfs(int position, int omit, vector<int> &visited, vector<vector<int>>& adjmat) {
    if (position == omit)
        return;
    visited[position] = 1;

    for (int i = 0; i < adjmat.size(); i++) {
        if (not visited[i] and adjmat[position][i])
            dfs(i, omit, visited, adjmat);
    }
}

void print_boundary(int N) {
    cout << "+";
    for (int i = 0; i < 2*N -1; i++)
        cout << "-";
    cout <<"+\n";
}
void print_row(vector<int> &v) {
    cout << "|";
    for (int i = 0; i < v.size(); i++)
        cout << (v[i]==0?"N":"Y") << "|";
    cout << "\n";
}

int main() {
    int ncases;
    cin >> ncases;
    for(int n = 1; n <= ncases; n++) {
        int N;
        cin >> N;
        vector<vector<int>> adjmat(N, vector<int>(N)), answer(N, vector<int>(N));
        vector<int> reachable(N);

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> adjmat[i][j];

        dfs(0, -1, reachable, adjmat);
        for (int omit = 0; omit < N; omit++) {
            vector<int> visited(N,0);
            dfs(0, omit, visited, adjmat);
            for(int i = 0; i < N; i++) {
                answer[omit][i] = (visited[i] != reachable[i]);
            }
        }

        cout << "Case " << n << ":\n";
        print_boundary(N);
        for(int i = 0; i < N; i++) {
            print_row(answer[i]);
            print_boundary(N);
        }

    }
}
