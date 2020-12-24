#!/usr/bin/env python3

# Free Weights
# https://open.kattis.com/problems/freeweights
#

import sys, os, bisect

def check(sh1, lim):
    """
    Check if lim is an upper bound for the weight
    you have to lift in sh1. One does not have to lift
    heavier weight if any pair  of heavier weights 
    is separated by weights less than or equal to lim
    """
    firstOverLim = None
    for s in sh1:
        if s > lim:
            if firstOverLim is None:
                firstOverLim = s
            elif firstOverLim == s:
                firstOverLim = None
            else:
                return False
    return True


def main():
    f = open('test') if 'TESTR' in os.environ else sys.stdin
    n = int(f.readline())
    sh1 = list(map(int, f.readline().split()))
    sh2 = list(map(int, f.readline().split()))

    # Find the largest unpaired weight in shelf one
    # max(s) will be the largest unpaired weight
    # This will be the lower bound on the weight which 
    # has to be lifted.
    s = set()
    for w in sh1:
        if w in s:
            s.remove(w)
        else:
            s.add(w)

    lo = 0 if len(s) == 0  else max(s)
    hi =  max(max(sh1), max(sh2))
    mid = None

    while lo < hi:
        mid = (lo + hi)//2
        if check(sh1, mid) and check(sh2, mid):
            hi = mid
        else:
            lo = mid + 1
    print(hi)

if __name__ == "__main__":
    main()