#!/usr/bin/env python3

#
# Traveling Monk
# https://open.kattis.com/problems/monk
#

import sys, os, bisect
from itertools import accumulate


def main():
    f = open('test') if 'TESTR' in os.environ else sys.stdin
    a, d = map(int, f.readline().split())

    ha = [0] * (a + 1)
    ta = [0] * (a + 1)
    for i in range(1, a+1):
        ha[i], ta[i] = map(int, f.readline().split())
    ha = list(accumulate(ha))
    ta = list(accumulate(ta))

    hd = [0] * (d + 1)
    td = [0] * (d + 1)
    for i in range(1, d + 1):
        hd[i], td[i] = map(int, f.readline().split())
    hd = list(accumulate(hd))
    td = list(accumulate(td))
    height = hd[-1]
    hd = list(map(lambda x: height -x, hd))

    if ta[-1] > td[-1]:
        td.append(ta[-1])
        hd.append(hd[-1])
    elif td[-1] > ta[-1]:
        ta.append(td[-1])
        ha.append(ha[-1])


    funcda = lambda t: func(hd, td, t) - func(ha, ta, t)
    tmin = 0

    # funcda is piecewise linear with integer endpoints
    # if funcda is 0 on an interval, its left end point
    # is an integer
    while funcda(tmin) > 0:
        tmin += 1
    if funcda(tmin) == 0:
        print(tmin)
        return
    tmin -= 1
    print(findRoot(funcda, tmin, ta[-1]))
    


def func(hh, tt, t):
    i = bisect.bisect_left(tt, t)
    t1 = tt[i-1]
    t2 = tt[i]
    h1 = hh[i-1]
    h2 = hh[i]

    return h1 + (t - t1)/(t2 -t1) * (h2 - h1)

def findRoot(f, l, r):
    fl = f(l)
    fr = f(r)
    if abs(fl - fr) < 1e-6:
        return l
    mid =  (l + r)/2
    fm = f(mid)
    if fm >= 0 and fl >= 0 or fm <= 0 and fl <= 0:
        return findRoot(f, mid, r)
    else:
        return findRoot(f, l, mid)

if __name__ == "__main__":
    main()