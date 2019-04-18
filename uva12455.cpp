#include<iostream>
#include<vector>


using namespace std;

bool dfs(vector<int>& v, int position, int sum, int target) {
    if (sum == target)
        return true;

    if (sum > target or position >= v.size()) //prune the dfs
        return false;
    return
        dfs(v, position+1, sum+v[position], target) or
        dfs(v, position+1, sum, target);
}


int main() {
    int ncases;
    cin >> ncases;
    while(ncases--) {
        int length, nrods;
        vector<int> rodlength;
        cin >> length;
        cin >> nrods;
        while (nrods--) {
            int t; cin >> t;
            rodlength.push_back(t);
        }
        if (dfs(rodlength, 0, 0, length))
            cout << "YES\n";
        else
            cout << "NO\n";

    }
}
