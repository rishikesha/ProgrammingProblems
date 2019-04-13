#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Aref {
    private:
        vector<int> C;
    public:
        const string name;
        const int baseaddress;
        const int sz;
        const int D;
        const vector<int> lower;
        const vector<int> upper;

        //Constructor
        Aref(string name_, int baseaddress_,
                int sz_, int D_, vector<int> lower_,
                vector<int> upper_) : name(name_),
        baseaddress(baseaddress_), sz(sz_), D(D_),
        lower(lower_),
        upper(upper_) {

            C.resize(D_ + 1);
            C[D_] = sz;

            for (int i = D_ - 1; i > 0; i--) {
                C[i] = C[i+1] * (upper[i] - lower[i] + 1);
            }

            C[0] = baseaddress;
            for(int i = 0; i < D; i++) {
                C[0] -= C[i+1] * lower[i];
            }
        }

        void getAddress() {
            vector<int> v(D);
            for (int i = 0; i < D; i++) {
                cin >> v[i];
            }

            int result = C[0];
            for (int i = 0; i< D; i++) {
                result += C[i+1] * v[i];
            }

            cout << name <<"[";
            for(int i = 0; i< D-1; i++) {
                cout << v[i] << ", ";
            }
            cout << v[D-1] <<"] = ";
            cout << result <<"\n";
        }
};



int main() {
    int N, R;
    vector<Aref> spaces;

    cin >> N;
    cin >> R;


    for (int i = 0; i < N; i++) {
        int tmp;
        string name;
        int baseaddress, sz, D;
        vector<int> lower;
        vector<int> upper;
        cin >> name >> baseaddress >> sz >> D;
        for (int i = 0; i < D; i++) {
            cin >> tmp; lower.push_back(tmp);
            cin >> tmp; upper.push_back(tmp);
        }
        spaces.push_back(Aref(name, baseaddress, sz, D, lower, upper));

    }

    for (int i = 0; i< R; i++) {
        string s;
        cin >> s;
        //int j = 0;
        //for (;spaces[j].name != s;j++);
        //spaces[j].getAddress();
        auto it = find_if(spaces.begin(), spaces.end(),
                [&s](const Aref& a){return a.name == s;});
        it->getAddress();
    }





}
