/* Rishikesh
 * UVA 417
 */
#include<iostream>
#include<string>
#include<algorithm>
#include<deque>
#include<map>

using namespace std;

map<string, int> m;

void generateValidWords() {
    deque<string> v, v2,v3;
    for (int i = 0; i< 26;i++) {
        v.push_back(string(1,'a'+i));
    }

    v2 = v;
    for(int i = 0; i < 4; i++) {
        for (string s : v2) {
            char c = s[s.length()-1];
            for (char j = c+1; j < 'a'+26; j++) {
                v3.push_back( s + string(1, j));
            }
        }
        v3.insert(v3.begin(), v.begin(), v.end());
        v2 = std::move(v3);
    }

    int count = 1;
    for (auto it  = v2.begin(); it != v2.end(); ++it) {
        m[*it] = count;
        count++;
    }
}

void generateValidWords2() { //More efficient in space and time
    deque<string> v;

    for (int i = 0; i< 26;i++) {
        v.push_back(string(1,'a'+i));
    }

    int lastbegin = 0, lastend=26;
    for(int i = 0; i < 4; i++) {
        int tmp = lastend;
        for(int j = lastbegin; j < lastend; j++) {
            string s = v[j];
            char c = s[s.length()-1];
            for (char j = c+1; j < 'a'+26; j++) {
                v.push_back( s + string(1, j));
            }
        }
        lastbegin = tmp;
        lastend = v.size();
    }
    int count = 1;
    for (auto it  = v.begin(); it != v.end(); ++it) {
        m[*it] = count;
        count++;
    }

}

typedef long long ll;

int main() {
    string s;
    generateValidWords2();
    while (getline(cin, s), s.length() > 0) {
        cout << m[s] << endl;
    }

}
