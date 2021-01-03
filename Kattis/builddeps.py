#!/usr/bin/env python3

# Build Dependencies
# https://open.kattis.com/problems/builddeps
# Could be made faster by using non recursive dfs, but this is elegant and passes.
#

import os, sys
from collections import deque, defaultdict
from enum import Enum

class Status(Enum):
    WHITE = 0
    GRAY = 1
    BLACK = 2


def main():
    sys.setrecursionlimit(100000)
    f = open('test') if 'TESTR' in os.environ else sys.stdin
    n = int(f.readline())
    G = defaultdict(lambda: set())
    for _ in range(n):
        src, deps = f.readline().strip().split(':')
        G[src] # make sure src is in the list of keys
        deps = deps.strip()
        if len(deps) != 0:
            deps = deps.split()
            for dep in deps:
                G[dep].add(src)
    
    status = {}
    for src in G.keys():
        status[src] = Status.WHITE

    changed = f.readline().strip()
    q = deque()
    dfs(G, changed, status, q)
    for fle in q:
        print(fle)


def dfs(G, fle, status, q:deque):
    status[fle] = Status.GRAY
    for nxt in G[fle]:
        if status[nxt] == Status.WHITE:
            dfs(G, nxt, status, q)
    status[fle] = Status.BLACK
    q.appendleft(fle)





if __name__ == "__main__":
    main()