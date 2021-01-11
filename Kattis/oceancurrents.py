#!/usr/bin/env python3

# Ocean Currents
# https://open.kattis.com/problems/oceancurrents
#
# This works but gives TLE on the largest test
# Any improvments would come at the cost of clarity, so I am
# leaving it like this. If you think that I missed something
# easy, please let me know. As I am writing this, there is
# a fast solution in Python3 which was accepted, but I
# do not know how he solved it.
# main() has the main logic


import os, sys, heapq
from math import inf, isinf
import heapq
import cProfile, io, pstats
from pstats import SortKey


def profile(func):
    def wrapper(*args, **kwargs):
        pr = cProfile.Profile()
        pr.enable()
        retval = func(*args, **kwargs)
        pr.disable()
        s = io.StringIO()
        sortby = SortKey.CUMULATIVE  # 'cumulative'
        ps = pstats.Stats(pr, stream=s).sort_stats(sortby)
        ps.print_stats()
        print(s.getvalue())
        return retval

    return wrapper
    




#@profile
def main():
    f = open('test') if 'TESTR' in os.environ else sys.stdin
    r, c = map(int, f.readline().split())
    flow = [list(map(int, list(f.readline().strip()))) for _ in range(r)]
    n = int(f.readline())
    for _ in range(n):
        rs, cs, rd, cd = map(int, f.readline().split())
        print(dijkstra(flow, rs-1, cs-1, rd-1, cd-1)) # convert to 0 based index

def dijkstra(flow, rs, cs, rd, cd):

    n , m = len(flow), len(flow[0])
    dist = [m*[inf] for _ in range(n)]
    finished = [m*[False] for _ in range(n)]
    dist[rs][cs] = 0
    pq = [(0, rs, cs)]
    while len(pq) != 0:
        (l, r, c) = heapq.heappop(pq)
        finished[r][c] = True

        if r == rd and c == cd:
            return l
        for (rn, cn) in neighbors(n, m , r, c, finished):
            w = weight(flow, rn, cn, r, c)
            if dist[rn][cn] > l + w:
                heapq.heappush(pq, (l+w, rn, cn))
                dist[rn][cn] = l + w


def neighbors(n, m, r, c, finished):
    disp = [-1, 0, 1]
    result = [(r+i, c+j) for i in disp for j in disp]
    return [(x,y) for (x,y) in result if x >= 0 and x < n and\
        y >= 0 and y < m and (x,y) != (r,c) and not finished[x][y]]

def weight(flow, rn, cn, r, c):
    d = {
        (-1,0) : 0,
        (-1, 1) : 1,
        (0, 1) : 2,
        (1, 1) : 3,
        (1, 0) : 4,
        (1, -1): 5,
        (0, -1): 6,
        (-1, -1): 7
    }
    
    a = (rn -r, cn -c)
    if flow[r][c] == d[a]:
        return 0
    else:
        return 1

if __name__ == "__main__":
    main()