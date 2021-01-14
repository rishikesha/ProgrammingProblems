#!/usr/bin/env python3

# Simplification
# https://open.kattis.com/problems/simplification
# 
# parentLeft and parentRight are essentially two Union Find (or DisjointSet) data structures.
# parentLeft merges the deleted point to the left. parentRight merges the deleted point to the right.
# These help quickly find the next undeleted point to the left or to the right of any given
# point.

import os, sys, heapq

f = open('test') if 'TESTR' in os.environ else sys.stdin

def main():
    n, m = map(int, f.readline().split())

    parentRight = list(range(n+1))
    parentLeft = list(range(n+1))

    points = []
    for _ in range(n+1):
        x,y = map(int, f.readline().split())
        points.append((x,y))
    
    pq = []
    for i in range(n-1):
        a = triangleArea([points[i], points[i+1], points[i+2]])
        pq.append((a, i, i+1, i+2))

    heapq.heapify(pq)
    discarded = set() # not really necessary. Can use parentLeft[i] != i to check for discarded

    ct = 0
    while ct < n - m:
        a, l, mm, r = heapq.heappop(pq) # mm since m is already used. Was a horrible bug before
        if l in discarded or mm in discarded or r in discarded:
            continue

        discarded.add(mm)
        print(mm)
        ct += 1

        parentLeft[mm] = findParent(parentLeft, l)
        parentRight[mm] = findParent(parentRight, r)

        if findParent(parentLeft, l) > 0:
            ll = findParent(parentLeft, findParent(parentLeft, l)-1)
            a = triangleArea([points[ll], points[l], points[r]])
            heapq.heappush(pq, (a, ll, l, r))
        
        if findParent(parentRight, r) < n:
            rr = findParent(parentRight, findParent(parentRight, r)+1)
            a = triangleArea([points[l], points[r], points[rr]])
            heapq.heappush(pq, (a, l, r, rr))





def findParent(parent, i):
    if parent[i] != i:
        parent[i] = findParent(parent, parent[i])
    return parent[i]



def triangleArea(t):
    [(x1,y1), (x2,y2), (x3,y3)] = t
    return abs(x2*y1 - x1*y2 + x3*y2 - x2*y3 + x1*y3 - x3*y1)/2

if __name__ == "__main__":
    main()
