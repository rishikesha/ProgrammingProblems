#!/usr/bin/env python3

# Expanding Rods
# https://open.kattis.com/problems/expandingrods
#
# Binary Search the Answer
# This problem requires understanding of geometry and trignometry
# If r is the radius of the circle, the angle of arc, theta = L'/r
# L = 2 * r * sin(theta/2)
# The displacement of the center is r - r * cos(theta/2)

import os, sys
from math import sin, pi, cos

f = open('test') if 'TESTR' in os.environ else sys.stdin

def solve(f, l, r, eps=1e-11):
    if r -l < eps:
        return l
    
    m = (l+r)/2
    if f(m) < 0:
        return solve(f, m, r)
    else:
        return solve(f, l, m)


def main():
    while True:
        L, n , C = f.readline().split()
        L = int(L)
        if L == -1:
            break
        n = int(n)
        C = float(C)
        if C == 0 or n == 0:
            print(f"{0.0000000000}")
        else:
            l = 0
            ff = lambda x: x -(1+n*C) * sin(x)
            r = pi 
            halftheta = solve(ff, l, r)
            #radius = L/theta
            #print(radius * (theta - sin(theta)))
            ans = L*(1+n*C) /(2*halftheta)* (1-cos(halftheta))
            print(f"{ans:0.9f}")




if __name__ == "__main__":
    main()