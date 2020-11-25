#!/usr/bin/env python3
#
# Flag Quiz https://open.kattis.com/problems/flagquiz
#

import os, sys, operator


def main():
    f = open(sys.argv[1]) if 'TESTR' in os.environ else sys.stdin
    f.readline()
    n = int(f.readline())
    M = [f.readline().strip().split(",") for _ in range(n)]
    dist = n *[0]
    for i in range(n):
        for j in range(n):
            dist[i] = max(dist[i], # Take the max of distance between M[i] and M[j] for all j in range(n)
                          sum(map(lambda x: operator.ne(*x),
                                  zip(M[i], M[j]))))
            

    a = min(dist)
    for i in range(n):
        if a == dist[i]:
            print(",".join(M[i]))




if __name__ == "__main__":
    main()