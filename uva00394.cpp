/* Rishikesh
 * UVA 00394 Mapmaker
 * Test passed
 */

#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<map>
#include<numeric>
#include<algorithm>

using namespace std;

struct arrdef {
    string name;
    int base_address;
    int D; //dimension
    vector<int> C;
};

void process(const map<string, arrdef> arrmap, const string& s) {
    istringstream iss(s);
    string name;
    iss >> name;
    const arrdef& a = arrmap.at(name);

    vector<int> v(a.D+1);

    for (int i = 1; i <= a.D; i++) {
        iss >> v[i];
    }
    cout << name << "[";
    int D = a.D;
    int phyadd = a.C[0];
    int x;
    for (int i = 1; i < D; i++) {
        cout << v[i] << ", ";
        phyadd +=  a.C[i] * v[i];
    }
    phyadd +=  a.C[D] * v[D];
    cout << v[D] << "] = " << phyadd << endl;
}

int main() {
#ifdef DEBUGUVA
    freopen("test", "r", stdin);
    cerr << "This is DEBUG\n";
#endif
    string s;
    int N, R;
    getline(cin, s);
    istringstream iss(s);
    iss >> N >> R;

    map <string, arrdef> arrmap;

    for (int i = 0; i < N; i++) {
        getline(cin, s);
        istringstream iss(s);
        arrdef a;
        int size;

        iss >> a.name >> a.base_address >> size >> a.D;

        a.C.resize(a.D + 1);

        vector<int> L(a.D + 1), U(a.D + 1);

        for(int j = 1; j <= a.D; j++) {
            iss >> L[j];
            iss >> U[j];
        }

        a.C[a.D] = size;

        for(int j = a.D - 1; j >= 1; j--) {
            a.C[j] = a.C[j+1] * (U[j+1] - L[j+1] + 1);
        }
        

        for (int j = 1; j <= a.D; j++) {
            L[j] *= a.C[j]; // Using L as temp storage
        }

        a.C[0] = a.base_address - accumulate(L.begin() + 1, L.end(), 0);

        arrmap[a.name] = std::move(a);
    }

    for (int i = 0; i < R; i++) {
        getline(cin, s);
        process(arrmap, s);
    }
}
