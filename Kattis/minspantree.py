#!/usr/bin/env python3

# Minimum Spanning Tree
# https://open.kattis.com/problems/minspantree
#
# The unstated assumption is that there can be two parallel edges 
# between any two vertices. Discard everything other than the
# lowest weight right in the beginning.


import os, sys, heapq
from collections import defaultdict
from math import inf,isinf

def main():
    f = open('test') if 'TESTR' in os.environ else sys.stdin
    while True:
        n, m = map(int, f.readline().split())
        if n == 0 and m == 0:
            break

        G = [set() for _ in range(n)] # Adjacency list
        weight = defaultdict(lambda : inf)

        for _ in range(m):
            u, v, w = map(int, f.readline().split())
            G[u].add(v)
            G[v].add(u)
            weight[(u,v)] = min(w, weight[(u,v)]) #make sure to use lower weight of two parallel edges
            weight[(v,u)] = min(w, weight[(v,u)])


        pq = []
        pq.append((0,0))
        for i in range(1, n):
            pq.append((inf, i))

        found = set()
        cost = [inf] * n
        cost[0] = 0
        pred = [None for _ in range(n)]
        while len(found) < n:
            w, i = heapq.heappop(pq)
            found.add(i)
            for v in G[i]:
                ww = weight[(i,v)]
                if v not in found and cost[v] > ww:
                    pred[v] = i
                    cost[v] = ww
                    heapq.heappush(pq, (ww, v))

        
        totalcost = sum(cost)
        if isinf(totalcost):
            print("Impossible")
        else:
            print(totalcost) 
            result =[(i,pred[i]) if i < pred[i] else (pred[i],i) for i in range(1,n)]
            result.sort()
            for x,y in result:
                print(x,y)
        
        



if __name__ == "__main__":
    main()