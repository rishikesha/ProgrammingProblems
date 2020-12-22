#!/usr/bin/env python3

#
# Firefly
# https://open.kattis.com/problems/firefly
#

import os, sys, bisect
from collections import namedtuple

def count(stalagmite, stalactite, h) -> int:
    n1 = len(stalagmite) - bisect.bisect_left(stalagmite,h)
    n2 = bisect.bisect_left(stalactite, h)
    return  n1 + n2


def main():
    f = open('test') if 'TESTR' in os.environ else sys.stdin
    N, H = map(int, f.readline().split())

    stalagmite = []
    stalactite = []
    for i in range(N):
        if (i & 1):
            stalactite.append(H - int(f.readline()))
        else:
            stalagmite.append(int(f.readline()))


    stalactite.sort()
    stalagmite.sort()


    answer = 0
    maxdestruction = 10**9
    for h in range(1,H+1):
        ct = count(stalagmite, stalactite, h)
        if ct < maxdestruction:
            maxdestruction = ct
            answer = 1
        elif ct == maxdestruction:
            answer += 1

    print(maxdestruction, answer)


if __name__ == "__main__":
    main()