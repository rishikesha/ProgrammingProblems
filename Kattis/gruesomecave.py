#!/usr/bin/env python3

# Gruesome Cave
# https://open.kattis.com/problems/gruesomecave
# In an infinite random walk confined to a finite possibilities as mentioned in
# the problem statement, one can show that the fraction of time a given tile is
# occupied is proportion to the number of neigbors it has. Write to me if you 
# want the proof.
# 

import sys, os, heapq
from math import inf, isinf
from fractions import Fraction

f = open('test') if 'TESTR' in os.environ else sys.stdin

def main():
    L, W = map(int, f.readline().split())
    cave = [f.readline().strip() for _ in range(L)]


    nbrs, weight, total, E, D = calculateProbabilitiesAndNbrs(cave)

    if total > 0:
        print(dijkstra(weight, nbrs, E, D)/total)
    else:
        print(0) #corresponds to no grue tiles





def calculateProbabilitiesAndNbrs(cave):
    L = len(cave)
    W = len(cave[0])
    nbrs = [[[] for j in range(W)] for i in range(L)]
    weight = [[0 for j in range(W)] for i in range(L)]
    total = 0
    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]
    E = D = None

    for i in range(L):
        for j in range(W):
            # Compute the adjacency list
            if cave[i][j] in [' ', 'E']:
                for k in range(4):
                    inext = i + dx[k]
                    jnext = j + dy[k]
                    if inext >= 0 and inext < L and jnext >= 0 and jnext < W and \
                                    cave[inext][jnext] == ' ':
                        nbrs[i][j].append((inext, jnext))

            # compute weights
            w = len(nbrs[i][j])
            if w == 0:
                weight[i][j] = inf
            elif cave[i][j] == ' ':
                weight[i][j] = w
                total += w

            # Find the location of Entrance and diamond
            if cave[i][j] == 'E':
                E = (i,j)
                weight[i][j] = 0
            if cave[i][j] == 'D':
                D = (i,j)
                weight[i][j] = 0
    
    # add D as a neighbor to adjacent tiles
    (i,j) = D
    for k in range(4):
        ni = i + dx[k]
        nj = j + dy[k]
        if ni >= 0 and ni < L and nj >= 0 and nj < W and cave[ni][nj] in ['E', ' ']:
            nbrs[ni][nj].append((i,j))

    return nbrs, weight, total, E, D
    


def dijkstra(weights, nbrs, E, D):
    (i,j) = E
    L = len(weights)
    W = len(weights[0])
    dist = [[inf] * W for _ in range(L)]
    pq = [(0,E)]
    while len(pq) > 0:
        d,T = heapq.heappop(pq)
        i,j = T
        dist[i][j] = d
        if T == D:
            return d

        for inext, jnext in nbrs[i][j]:
            if isinf(dist[inext][jnext]):
                heapq.heappush(pq, (d+weights[inext][jnext], (inext, jnext)))
        

if __name__ == "__main__":
    main()
