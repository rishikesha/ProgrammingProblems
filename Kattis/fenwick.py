#!/usr/bin/env python3

# Fenwick Tree
# https://open.kattis.com/problems/fenwick
# 

import os, sys

class FenwickTree:
    def __init__(self, N):
        self.N = N
        self.a = (N+2) * [0]
    
    def increment(self, i, x):
        k = i + 1
        while k <= self.N + 1:
            self.a[k] += x
            k = k + (k & (-k))

    def query(self, i):
        result = 0
        k = i
        while k > 0:
            result += self.a[k]
            k = k - (k & (-k))
        return result

def main():
    f = open('test') if 'TESTR' in os.environ else sys.stdin
    N, Q = map(int, f.readline().split())

    fenwick = FenwickTree(N)
    for _ in range(Q):
        l = f.readline().split()
        if l[0] == '+':
            i, x = int(l[1]), int(l[2])
            fenwick.increment(i, x)
        elif l[0] == '?':
            i = int(l[1])
            print(fenwick.query(i))





if __name__ == "__main__":
    main()