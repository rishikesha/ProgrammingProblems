#!/usr/bin/env python3

if __name__ == "__main__":
    n = int(input())
    for _ in range(n):
        m = int(input())
        from math import sqrt
        print((int((sqrt(1+8*m) - 1)/2)))

