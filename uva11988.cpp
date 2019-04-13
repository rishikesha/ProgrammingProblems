#include<iostream>
#include<list>
#include<string>

using namespace std;

int main() {
    string s;
    while (getline(cin,s), s.length() > 0) {
        list<char> text;
        list<char>::iterator it = text.end();
        for(char c : s) {

            if (c == '[') {
                it = text.begin();
            } else if (c == ']') {
                it = text.end();
            } else {
                text.insert(it, c);
            }
        }
        for (it = text.begin(); it != text.end(); it++) {
            cout << *it;
        }
        cout << "\n";
    }

}
