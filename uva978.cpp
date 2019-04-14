#include<iostream>
#include<queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        priority_queue<int> green, blue;
        int b, sg, sb;
        cin >> b >> sg >>sb;
        vector<int> gb(b,0), bb(b,0);
        for (int i = 0; i < sg; i++) {
            int tmp;
            cin>>tmp;
            green.push(tmp);
        }
        for (int i = 0; i < sb; i++) {
            int tmp;
            cin>>tmp;
            blue.push(tmp);
        }

        while(not (green.empty() or blue.empty())) {
            for(int i = 0; i < b; i++) {
                if (green.empty() or blue.empty())
                    break;
                gb[i] = green.top() - blue.top();
                bb[i] = -gb[i];
                green.pop(); blue.pop();
            }

            for(int i = 0; i < b; i++) {
                if (gb[i] > 0)
                    green.push(gb[i]);
                if (bb[i] > 0)
                    blue.push(bb[i]);
                gb[i] = bb[i] = 0;
            }
        }
        if (not green.empty()) {
            printf("green wins\n");
            while(not green.empty()) {
                printf("%d\n", green.top());
                green.pop();
            }
        } else if (not blue.empty()) {
            printf("blue wins\n");
            while(not blue.empty()) {
                printf("%d\n", blue.top());
                blue.pop();
            }
        } else 
            printf("green and blue died\n");

        if(n)
            printf("\n");


    }
}
