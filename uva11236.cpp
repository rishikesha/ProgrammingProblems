
#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<iomanip>
#include<cstdint>
#include<numeric>

const int64_t MILLION=1000000;
const int64_t TWOTHOUSAND=2000;


using namespace std;

void call() {
    printf("called here");
}


int main() {
    for (int64_t i1 =1; i1<= TWOTHOUSAND; i1++) {
        for(int64_t i2 = i1; i2 <= TWOTHOUSAND; i2++) {
            if (i1+i2 > TWOTHOUSAND)
                break;
            for(int64_t i3 = i2; i3 <= TWOTHOUSAND; i3++) {
                int64_t sum, prod;
                sum  = i1 + i2 + i3;
                if (sum > TWOTHOUSAND )
                    break;

                prod = i1 * i2 * i3;

                if (prod <= MILLION or (sum * MILLION) % (prod - MILLION) != 0)
                    continue;

                int64_t i4 = (sum * MILLION) / (prod - MILLION);
                sum += i4;
                if (i4 < i3 or sum > TWOTHOUSAND)
                    continue;

                printf("%d.%02lld %lld.%02lld %lld.%02lld %lld.%02lld\n",i1/100,i1%100,
                        i2/100, i2%100, i3/100, i3%100, i4/100, i4%100);
            }
        }
    }
}
