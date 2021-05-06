#!/usr/bin/env python3
import sys, os

# Fast Food Prizes
# https://open.kattis.com/problems/fastfood
# This is an array manipulation problem. Use greedy approach, although
# it is not mentioned in the problem. Optimizing the prize value
# would be a much harder problem.
#

f = open(sys.argv[1]) if 'TESTR' in os.environ else sys.stdin

def solve():
    n, m = map(int, f.readline().split())
    prizevalue = [0] * n
    requiredstickers = [[] for _ in range(n)]


    for i in range(n):
        tmp = list(map(int, f.readline().split()))
        requiredstickers[i] = [x-1 for x in tmp[1:-1]]
        prizevalue[i] = tmp[-1]
    numstickers = list(map(int, f.readline().split()))

    totalvalue = 0
    for i in range(n):
        while all([numstickers[j] > 0 for j in requiredstickers[i]]):
            totalvalue += prizevalue[i]
            for j in requiredstickers[i]:
                numstickers[j] -= 1
    print(totalvalue)









if __name__ == "__main__":
    ncases = int(f.readline())
    for _ in range(ncases):
        solve()