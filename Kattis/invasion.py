#!/usr/bin/env python3

# Invasion
# https://open.kattis.com/problems/invasion
#
#

import os, sys, heapq
from math import isinf, inf

f = open('test') if 'TESTR' in os.environ else sys.stdin

def main():
    while True:
        N, M, A, K = map(int, f.readline().split())
        if N == 0 and M == 0 and A == 0 and K == 0:
            break
        adj = [[] for _ in range(N)]
        for _ in range(M):
            u, v, w = map(int, f.readline().split())
            u -= 1
            v -= 1
            adj[u].append((v,w))
            adj[v].append((u,w))
        alienbases = []
        for _ in range(A):
            a = int(f.readline())
            alienbases.append(a-1)

        unsafe = set()
        dist = [inf] * N
        for i in range(A):
            dijkstra(adj, dist, unsafe, alienbases[i], K)
            print(N - len(unsafe))
        print()


def dijkstra(adj, dist, unsafe, a, K):
    pq = [(0,a)]

    while len(pq) > 0:
        d, u = heapq.heappop(pq)

        if d >= K: # Every town after this is at least distance K from alien base
            return
        else:
            unsafe.add(u) # add this down to unsafe

        for (v,w) in adj[u]:
            if dist[v] > d + w: # Process only if new distance is less than old
                newd = d + w
                heapq.heappush(pq, (newd, v))
                dist[v] = newd



if __name__ == "__main__":
    main()