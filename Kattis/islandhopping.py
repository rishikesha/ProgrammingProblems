#!/usr/bin/env python3

# Island Hopping
# https://open.kattis.com/problems/islandhopping
#

import os, sys, heapq

class DisjointSet:
    def __init__(self, N):
        self.parent = list(range(N+1))
    
    def findSet(self, n):
        if self.parent[n] != n:
            self.parent[n] = self.findSet(self.parent[n])
        return self.parent[n]

    def union(self, x, y):
        u = self.findSet(x)
        v = self.findSet(y)
        if u < v:
            self.parent[v] = u
        elif v < u:
            self.parent[u] = v

def dist(x,y):
    return (x[0] - y[0])**2 + (x[1] - y[1])**2 #using sqrt here will give TLE

def main():
    f = open('test') if 'TESTR' in os.environ else sys.stdin
    ncases = int(f.readline())
    for _ in range(ncases):
        m = int(f.readline())
        coordinates = []
        for  _ in range(m):
            x, y = map(float, f.readline().split())
            coordinates.append((x,y))
        distances = [(dist(coordinates[i], coordinates[j]), i,j) 
                                for i in range(m) for  j in range(i)]
        heapq.heapify(distances)
        totaldist = 0
        ds = DisjointSet(m)
        for _ in range(m-1):
            added = False
            while not added:
                (d, i, j) = heapq.heappop(distances)
                if ds.findSet(i) != ds.findSet(j):
                    from math import sqrt
                    totaldist += sqrt(d)
                    ds.union(i,j)
                    added = True
        print(f"{totaldist:0.4f}")
        

if __name__ == "__main__":
    main()