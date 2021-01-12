#!/usr/bin/env python3

#
# Single source shortest path, non-negative weights
#  https://open.kattis.com/problems/shortestpath1
# 

import os, sys, heapq
from math import inf, isinf

f = open('test') if 'TESTR' in os.environ else sys.stdin

def main(line):
    n, m, q, s = map(int, line.split())
    adj = [[] for _ in range(n)]
    for _ in range(m):
        u, v, w = map(int, f.readline().split())
        adj[u].append((v,w))
        #adj[v].append((u,w))

    dist = n * [inf]

    dijkstra(adj, dist, s)

    for _ in range(q):
        d = int(f.readline())
        if isinf(dist[d]):
            print("Impossible")
        else:
            print(dist[d])


def dijkstra(adj, dist, s):
    pq = [(0,s)]

    while len(pq) > 0:
        d, u = heapq.heappop(pq)
        if isinf(dist[u]):
            dist[u] = d
            for (v,w) in adj[u]:
                if isinf(dist[v]):
                    heapq.heappush(pq, (w+d, v))
    


if __name__ == "__main__":
    while True:
        line = f.readline()
        a,b,c,d = map(int, line.split())
        if a == 0:
            break
        main(line)
        print()


