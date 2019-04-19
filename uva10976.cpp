/* Rishikesh
 * UVA 10976
 */
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main() {
    string s;
    while (getline(cin, s), s.length()) {
        istringstream iss(s);
        int n; iss >>n;
        int answer = 0;
        for (int i = n+1; i <= 2*n; i++) {
            if ((i*n) %(i - n) == 0) {
                answer++;
            }
        }

        cout << answer << endl;
        for (int i = n+1; i <= 2*n; i++) {
            if ((i*n) %(i - n) == 0) {
                printf("1/%d = 1/%d + 1/%d\n", n, (i*n)/(i-n), i);
            }
        }
    }
}
