#!/usr/bin/env python3

# All Pairs Shortest Path
# https://open.kattis.com/problems/allpairspath
#
# Floyd Warshall algorithm

import os, sys
from math import inf, isinf

f = open('test') if 'TESTR' in os.environ else sys.stdin

def main():
    while True:
        n,m,q = map(int, f.readline().split())
        if n == 0:
            break

        # Distance matrix
        D = [[inf] * n for _ in range(n)]
        Daux = [[inf] * n for _ in range(n)]
        for i in range(n):
            D[i][i] = 0
    
        for _ in range(m):
            u,v,w = map(int, f.readline().split())
            D[u][v] = min(D[u][v], w) # Easy to miss implicit assumption that there are possibly
                                      # many links between any given pair of nodes. Choose only lowest weight.

        for k in range(n):
            for i in range(n):
                for j in range(n):
                    Daux[i][j] = min(D[i][j], D[i][k]+D[k][j])
            D,Daux = Daux, D

        for _ in range(q):
            u, v = map(int, f.readline().split())
            negcycle = any([D[k][k] < 0 and D[u][k] < inf and D[k][v] < inf for k in range(n)])
            if negcycle:
                print("-Infinity")
            elif isinf(D[u][v]):
                print("Impossible")
            else:
                print(D[u][v])
        print()


if __name__ == "__main__":
    main()
