#!/usr/bin/env python3

# Out of Sorts
# https://open.kattis.com/problems/outofsorts
#
# Note: Recursive version of binary search will get "Time Limit Exceeded"

import os, sys

def canfind(a, l, r, x):
    while l <= r:
        m = (l + r)//2
        if a[m] == x:
            return True
        elif a[m] < x:
            l = m + 1
        else:
            r = m - 1
    else:
        return False

def generate(n, m, a, c, x):
    result = n*[0]
    for i  in range(n):
        x = (a * x + c) % m
        result[i] = x
    return result

def main():
    f = open('test') if 'TESTR' in os.environ else sys.stdin
    n, m, a, c, x0 = list(map(int, f.readline().split()))
    seq = generate(n, m, a, c, x0)
    found = set()
    for i in range(len(seq)):
        if canfind(seq, 0, len(seq)-1, seq[i]):
            found.add(seq[i])
    print(len(found))


if __name__ == "__main__":
    main()
