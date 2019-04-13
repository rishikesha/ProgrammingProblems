#include<cstdio>
#include<string>

typedef long long ll;

using namespace std;


int main() {
    int N;
    scanf("%d\n", &N);
    int K, v, M;
    unsigned char c;
    int value[256] = {0};
    char *line;
    size_t linesize=10100;
    line = (char *) malloc(linesize * sizeof(char));

    for (int i = 0 ; i< N; i++) {

        scanf("%d\n",&K);

        for(int i = 0; i< K; i++) {
            scanf("%c %d\n", &c, &v);
            value[c] = v;
        }

        scanf("%d\n",&M);


        ll answer = 0;
        for (int m = 0; m < M; m++) {
            getline(&line, &linesize, stdin);

            for(int i = 0; line[i]; i++) {
                answer += value[line[i]];
            }
        }

        printf("%lld.",answer/100);
        answer %= 100;
        if (answer < 10) {
            printf("0%lld$\n",answer);
        } else {
            printf("%lld$\n",answer);
        }

    }
}
