#!/usr/bin/env python3

#
# Numbers On a Tree
# https://open.kattis.com/problems/numbertree

import os, sys

def main():
    f = open(sys.argv[1]) if 'TESTR' in os.environ else sys.stdin
    tmp = f.readline().split() #needed because sometimes there is no second argument
    if len(tmp) == 2:
        H,s = tmp
    else:
        H = tmp[0]
        s = ""
    H = int(H) +1
    N = (1 << H) - 1
    x = 1
    for c in s:
        if c == 'L':
            x = 2*x
        else:
            x = 2*x + 1
    print(N-x+1)


if __name__ == "__main__":
    main()