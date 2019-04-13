#include<iostream>
#include<string>
#include<map>
#include<cstdio>
using namespace std;

int main() {
    std::map<string, string> m = {
        {"HELLO", "ENGLISH"},
        {"HOLA", "SPANISH"},
        {"HALLO", "GERMAN"},
        {"BONJOUR", "FRENCH"},
        {"CIAO", "ITALIAN"},
        {"ZDRAVSTVUJTE", "RUSSIAN"}};

    std::string s;
    int i = 1;
    while(true) {
        std::cin >> s;
        if (s=="#")
            break;
        std::printf("Case %d: %s\n", i, m[s].c_str());
        i++;
    }
}
