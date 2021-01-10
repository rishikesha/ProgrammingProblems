#!/usr/bin/env python3

# Grid
# https://open.kattis.com/problems/grid

import os, sys
from collections import deque
from math  import inf, isinf



def main():
    f = open('test') if 'TESTR' in os.environ else sys.stdin
    n , m = map(int, f.readline().split())
    grid = [list(map(int, list(f.readline().strip()))) for _ in range(n)]
    print(bfs(grid, (0,0)))

def neighbors(n, m, r, c, k):
    result = [(r-k,c), (r+k,c), (r, c-k), (r,c+k)] if k != 0 else []
    return [(x,y) for (x,y) in result if x >= 0 and y >=0 and x < n and y < m]

def bfs(grid, start):
    n = len(grid)
    m = len(grid[0])
    r, c = start

    q = deque([start])
    dist = [m*[inf] for _ in range(n)]
    dist[r][c] = 0

    while len(q) > 0:
        r,c = q.popleft()
        for (r1, c1) in neighbors(n, m, r, c, grid[r][c]):
            if isinf(dist[r1][c1]):
                dist[r1][c1] = dist[r][c] + 1
                q.append((r1,c1))
                if r1 == n -1 and c1 == m -1:
                    return dist[r1][c1]
    return -1
    



if __name__ == "__main__":
    main()