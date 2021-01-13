#!/usr/bin/env python3

# Traffic
# https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=1390
#
# Use Bellman Ford. Make sure to check if any juction is a part of negative weight cycle. 
# It might have a earning >= 3 at the end of Bellman Ford, but if it is a part of 
# negative weight cycle, set the earnings to a negative number.

import os, sys
from math import inf, isinf

f = open('test') if 'TESTR' in os.environ else sys.stdin

def main():
    setnumber = 1
    while True:
        line = f.readline()
        if len(line)  < 2:
            break
        line = map(int, line.split())
        n = next(line)
        busyness = list(line)
        r = int(f.readline())
        adj =[[] for _ in range(n)]
        for _ in range(r):
            a,b = map(int, f.readline().split())
            adj[a-1].append(b-1)

        print(f"Set #{setnumber}")
        setnumber += 1
        q = int(f.readline())
        earnings = n * [inf]
        bellmanford(adj, earnings, busyness)
        for _ in range(q):
            i = int(f.readline())
            if earnings[i-1] < 3 or isinf(earnings[i-1]):
                print("?")
            else:
                print(earnings[i-1])

def bellmanford(adj, earnings, busyness):
    n = len(adj)
    earnings[0] = 0
    for _ in range(n-1):
        # Relax all edges
        for i in range(n):
            for j in adj[i]:
                newearnings = earnings[i] + (busyness[j] - busyness[i])**3
                if earnings[j] >  newearnings:
                    earnings[j] = newearnings
    
    # check which junctions are part of negative cycle
    # and set earnings to -1 (or anything less than 3)
    for i in range(n):
        for j in adj[i]:
            newearnings = earnings[i] + (busyness[j] - busyness[i])**3
            if newearnings < earnings[j]:
                earnings[j] = -1


if __name__ == "__main__":
    main()
