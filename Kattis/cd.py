#!/usr/bin/env python3

#
# CD
# https://open.kattis.com/problems/cd

import os, sys
from collections import Counter

def main():
    f = open(sys.argv[1]) if 'TESTR' in os.environ else sys.stdin
    while True:
        cds = set()
        N, M = map(int, f.readline().split())
        if N==0 and M==0:
            break
        ans = 0
        for _ in range(N+M):
            n = int(f.readline())
            if n in cds:
                ans += 1
            cds.add(n)
        print(ans)

    


if __name__ == "__main__":
    main()