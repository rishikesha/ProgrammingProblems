#!/usr/bin/env python3
# This solution gets TLE
#

if __name__ == "__main__":
    while True:
        n,k = map(int, input().split())
        if n  == 0:
            break

        aprev = [1] * (n+1)

        for i in range(2, k+1):
            acurr = [1] * (n+1)
            for j in range(n+1):
                for  u in range(j):
                    acurr[j]  = (acurr[j] + aprev[u]) % 1000000
            aprev = acurr
        print(aprev[n])

