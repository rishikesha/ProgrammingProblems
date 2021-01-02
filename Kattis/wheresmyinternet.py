#!/usr/bin/env python3

# Where's my internet
# https://open.kattis.com/problems/wheresmyinternet
#

import os, sys

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
    

def main():
    f = open('test') if 'TESTR' in os.environ else sys.stdin
    N, M = map(int, f.readline().split())
    ds = DisjointSet(N)
    for  _ in range(M):
        a,b = map(int, f.readline().split())
        ds.union(a,b)
    
    connected = True
    for i in range(1,N+1):
        if ds.findSet(i) != 1:
            connected = False
            print(i)
    if connected:
        print("Connected")

if __name__ == "__main__":
    main()