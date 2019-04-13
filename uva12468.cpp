#include<cstdio>
#include<algorithm>

using namespace std;


int main() {
    int c,n;

    while(true) {
        scanf("%d %d", &c, &n);
        if (c < 0)
            return 0;

        int result=1000;
        result = min(result, n-c>=0?n-c:n-c+100);
        result = min(result, c-n>=0?c-n:c-n+100);


        printf("%d\n", result);
    }
}
