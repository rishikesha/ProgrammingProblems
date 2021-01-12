#!/usr/bin/env python3


# Beehives
# https://open.kattis.com/problems/beehives2
#
#

import os, sys, heapq
from collections import deque
from math import inf, isinf


def main():
    f = open('test') if 'TESTR' in os.environ else sys.stdin
    n, m = map(int, f.readline().split())

    edges = [[] for _ in range(n)]
    for _ in range(m):
        a, b = map(int, f.readline().split())
        edges[a].append(b)
        edges[b].append(a)
    
    mincycle = inf
    for i in range(n):
        mincycle = min(mincycle, bfs(i, edges))
    if isinf(mincycle):
        print("impossible")
    else:
        print(mincycle)


def bfs(i, edges):
    q = deque([i])
    n = len(edges)
    dist = n*[inf]
    prev = n *[None]
    dist[i] = 0
    girth = inf
    done = False
    while not done and len(q) > 0:
        u = q.popleft()
        for v in edges[u]:
            if isinf(dist[v]):
                dist[v] = dist[u] + 1
                prev[v] = u
                q.append(v)
            elif v != prev[u]:
                girth = min(girth, dist[u] + dist[v] + 1)
                done =  (dist[v] > (girth >> 1) + 1)
    return girth



if __name__ == "__main__":
    main()