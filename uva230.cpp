#include<iostream>
#include<cstdio>
#include<vector>
#include<string>

using namespace std;

int main() {
    vector<string> catalog;
    vector<int> status;
    string tmp, action, book;
    while (true) {
        cin >> tmp;
        if (tmp == "END")
            break;
        int n = tmp.find("\"", 1);
        catalog.push_back(tmp.substr(0,n+1));
        status.push_back(1);
    }

    while(true) {
        cin >> action;
        if (action == "END")
            break;
        cin >> book;

    }

}
