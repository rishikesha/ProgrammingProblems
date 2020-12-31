#!/usr/bin/env python3

# Air Conditioned Minions
# https://open.kattis.com/problems/airconditioned
#

import os, sys

def main():
    f = open('test') if 'TESTR' in os.environ else sys.stdin
    n = int(f.readline())
    interval = []
    for _ in range(n):
        a,b = map(int, f.readline().split())
        interval.append((a,b))
    interval.sort(key= lambda x: x[1])
    answer = 0
    prevend = -1
    for (a,b) in interval:
        if a > prevend:
            answer += 1
            prevend = b
    print(answer)


if __name__ == "__main__":
    main()