#!/usr/bin/env python3

# Magical Cows
# https://open.kattis.com/problems/magicalcows
#
# Ignore the discussion about ceil and floor functions. After doubling
# we always have twice the number of cows.
#

import sys, os, copy
from collections import Counter

def solve(counter : Counter, d : int, limit : int) -> int:
    """
    Simulate the problem for d days and give out the number of
    farms at the end of d days. The raw formula is also pretty easy.
    """
    for i in range(d):
        counter2 = Counter()
        for k in counter.keys():
            if 2 * k > limit:
                counter2[k] += 2 * counter[k]
            else:
                counter2[2*k] += counter[k]
        counter = counter2
    return sum(counter.values())


if __name__ == "__main__":
    f = open("test") if 'TESTR' in os.environ else sys.stdin
    C, N, M = map(int, f.readline().split())

    counter = Counter()

    for _ in range(N):
        counter[int(f.readline())] += 1
    for _ in range(M):
        d = int(f.readline())
        print(solve(counter, d, C))