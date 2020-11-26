#!/usr/bin/env python3
#
# Sort! sort! and sort!!!
# https://onlinejudge.org/external/113/11321.pdf
# https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=25&page=show_problem&problem=2296

import os, sys

def main():
    f = open(sys.argv[1]) if 'TESTR' in os.environ else sys.stdin
    while True:
        N, M = map(int, f.readline().split())
        print(N, M)
        if N==0 and M==0:
            break
        arr = [int(f.readline()) for _ in range(N)]
        def key(x):
            return (abs(x) % M * (x/abs(x)) if x != 0 else 0 , # this is needed because of difference in c mod and python mod
                     not bool(x % 2), \
                    -x if x % 2 else x \
                    )
        arr.sort(key=key)
        for x in arr:
            print(x)






if __name__ == "__main__":
    main()