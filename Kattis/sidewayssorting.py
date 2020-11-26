#!/usr/bin/env python3

# https://open.kattis.com/problems/sidewayssorting

import os, sys


def main():
    f = open(sys.argv[1]) if 'TESTR' in os.environ else sys.stdin
    while True:
        n,m = map(int, f.readline().split())
        if n == 0 and m == 0:
            break

        tps = []
        for _ in range(n):
            s = list(f.readline().strip())
            tps.append(s)

        tps = [[x[i] for x in tps] for i in range(m)] #get transpose
        tps = ["".join(x) for x in tps] #convert list of chars to strings
        tps.sort(key = lambda x: x.lower()) #sort strings
        tps = [[x[i] for x in tps] for i in range(n)]
        tps = ["".join(x) for x in tps]
        for s in tps:
            print(s)
        print()


if __name__  == "__main__":
    main()