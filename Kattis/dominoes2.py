#!/usr/bin/env python3

# Dominoes 2
# https://open.kattis.com/problems/dominoes2
#

import os, sys

def dfs(G, v, visited):
    visited[v] = True
    for w in G[v]:
        if not visited[w]:
            dfs(G,w,visited)


def main():
    f = open('test') if 'TESTR' in os.environ else sys.stdin
    ncases = int(f.readline())

    for _ in range(ncases):
        n, m, l = map(int, f.readline().split())
        G = [[] for _ in range(n+1)]
        for _ in range(m):
            a, b = map(int, f.readline().split())
            G[a].append(b)
        
        visited = [False for _ in range(n+1)]
        for _ in range(l):
            v = int(f.readline())
            if not visited[v]:
                dfs(G,v, visited)
        print(sum(visited))

if __name__ == "__main__":
    main()