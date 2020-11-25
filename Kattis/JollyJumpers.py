#!/usr/bin/env python3

# https://open.kattis.com/problems/jollyjumpers

import os
import sys


def main():
    f = open(sys.argv[1]) if 'TESTR' in os.environ else sys.stdin
    while True:
        try:
            a = list(map(int,f.readline().split()))
            if len(a) == 0:
                break
            n = a[0]
            a = a[1:]
            b = set([abs(a[i] - a[i-1]) for i in range(1,len(a))])
            if all(map(lambda x: x in b, range(1,n))):
                print("Jolly")
            else:
                print("Not jolly")
        except EOFError:
            break

if __name__ == "__main__":
    main()