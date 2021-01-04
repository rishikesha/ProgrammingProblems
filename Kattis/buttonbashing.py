#!/usr/bin/env python3

# Button Bashing
# https://open.kattis.com/problems/buttonbashing
#
#

import os, sys
from collections import deque
from math import inf, isinf


def main():
    f = open('test') if 'TESTR' in os.environ else sys.stdin
    ncases = int(f.readline())
    for _ in range(ncases):
        n, cookingtime = map(int, f.readline().split())
        seconds = list(map(int, f.readline().split()))
        presses = [inf] * 3601
        presses[0] = 0
        q = deque([0])
        while len(q) != 0:
            t1 = q.popleft()
            for addedtime in seconds:
                t2 = min(max(0, t1 + addedtime), 3600)
                if isinf(presses[t2]):
                    presses[t2] = presses[t1] + 1
                    q.append(t2)
        addedsecs  = 0
        while cookingtime <= 3600 and isinf(presses[cookingtime + addedsecs]):
            addedsecs += 1
        print(presses[cookingtime+addedsecs], addedsecs)
        
        


if __name__ == "__main__":
    main()