#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

void f(int g[3][3], int gg[3][3]) {
    gg[0][0] = (g[0][1] + g[1][0]) % 2;
    gg[0][1] = (g[0][0] + g[0][2] + g[1][1]) % 2;
    gg[0][2] = (g[0][1] + g[1][2]) % 2;
    gg[1][0] = (g[0][0] + g[2][0] + g[1][1]) % 2;
    gg[1][1] = (g[0][1] + g[1][0] + g[1][2] + g[2][1]) % 2;
    gg[1][2] = (g[0][2] + g[1][1]+ g[2][2]) % 2;
    gg[2][0] = (g[1][0] + g[2][1]) % 2;
    gg[2][1] = (g[2][0] + g[2][2] + g[1][1]) % 2;
    gg[2][2] = (g[2][1] + g[1][2]) % 2;
}

void printMatrix(int a[3][3]) {
    for (int i = 0; i< 3;i++) {
        printf("%d %d %d\n", a[i][0], a[i][1], a[i][2]);
    }
}

bool checkEqual(int a[3][3], int b[3][3]) {
    bool answer = true;
    for (int i = 0; i< 3;i++)
        for(int j = 0; j < 3; j++)
            answer = answer and (a[i][j] == b[i][j]);
    return answer;
}

void readMatrix(int g[3][3]) {
    string s;
    for (int i = 0; i< 3; i++) {
        cin >> s;
        for(int j = 0; j < 3; j++) {
            if (s[j] == '0')
                g[i][j] = 0;
            else
                g[i][j] = 1;
        }
    }
}


int main() {
    int n, g[3][3], h[3][3];
    int hh[3][3] {{0,0,0}, {0,0,0},{0,0,0}};

    cin >> n;
    while (n-- > 0) {
        readMatrix(g);
        int i = -1;
        while(not checkEqual(g,hh) and i < 513) {
            f(g,h);
            i++;
            swap(g,h);
        }

        printf("%d\n", i);
    }
}
