#include<cstdio>

using namespace std;

int months[102];
float deprate[102];

int main() {
    while (true) {
        int dur, recs;
        float down, loan, value;
        scanf("%d %f %f %d",&dur, &down, &loan, &recs);
        if (dur < 0)
            return 0;

        float installment = loan/dur;
        value = loan + down;

        for(int i = 0; i < recs; i++) {
            scanf("%d %f", months+i, deprate+i);
        }

        float depr = 0;
        int j = 0;
        for(int i = 0; i<= dur; i++) {
            if ( j < recs and i  == months[j]) {
                depr = deprate[j];
                j++;
            }
            value = (1-depr)*value;
            //printf("value - loan = %f\n", value - loan);
            if (value >= loan) {
                if ( i == 1)
                    printf("1 month\n");
                else
                    printf("%d months\n", i);
                break;
            }

            loan -= installment;
        }

    }
}
