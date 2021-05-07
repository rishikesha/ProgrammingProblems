#!/usr/bin/env python3

# Wizard of Odds
# https://open.kattis.com/problems/wizardofodds
# 
# This checks if N-1 needs less than or equal to K bits.

import os,sys

f = open(sys.argv[1]) if 'TESTR' in os.environ else sys.stdin

def solve(N, K):
    N -= 1
    while N > 0:
        N = N >> 1
        K -= 1
    if K >= 0:
        print("Your wish is granted!")
    else:
        print("You will become a flying monkey!")

if __name__ == "__main__":
    N, K = map(int, f.readline().split())
    solve(N, K)

