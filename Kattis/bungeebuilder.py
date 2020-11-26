#!/usr/bin/env python3

#
# Bungee Builder
# https://open.kattis.com/problems/bungeebuilder
#

import os, sys
from itertools import accumulate


def main(): # with two lists accumulating the max height from left and right
    f = open(sys.argv[1]) if 'TESTR' in  os.environ else sys.stdin
    N = int(f.readline())
    heights =  list(map(int, f.readline().split()))
    leftacc = list(accumulate(heights, max))
    rightacc = list(reversed(list(accumulate(reversed(heights), max))))
    ans = 0
    for i in range(N):
        ans = max(ans, min(leftacc[i], rightacc[i]) - heights[i])
    print(ans)






if __name__ == "__main__":
    main()