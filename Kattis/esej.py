#!/usr/bin/env python3

#
# Esej
# https://open.kattis.com/problems/esej
#

import string, random, os, sys

def main():
    A,B = map(int, input().split())
    C = max(A,B//2)
    lst = list(string.ascii_lowercase)
    s1 = list(string.ascii_lowercase)
    while len(s1) < C:
        s2 = []
        for w in s1:
            for c in lst:
                s2.append(w+c)
        s1 = s2
    ans = " ".join(s1[:C])
    print(ans)




if __name__ == "__main__":
    main()