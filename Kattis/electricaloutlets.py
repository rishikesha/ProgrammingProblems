#/usr/bin/env python3

# Electrical Outlets
# https://open.kattis.com/problems/electricaloutlets

import os, sys

f = open("test") if 'TESTR' in os.environ else sys.stdin

if __name__ == "__main__":
    N = int(f.readline())
    for _ in range(N):
        a = list(map(int, f.readline().split()))
        n = sum(a[1:]) # total number of outlets in all the power strips
        print(n - a[0] + 1)
    
