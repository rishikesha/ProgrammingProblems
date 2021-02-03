#!/usr/bin/env python3

# UVA 11167 -- Monkeys in the Emei Mountain
# https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=2108

# The implementation of maxflow is taken from 
# https://github.com/stevenhalim/cpbook-code/blob/master/ch8/maxflow.py
# Dinic's algorithm is much faster than Edmond Karp algorithm for solving this problem

import os, sys
from collections import deque
from math import inf, isinf

import cProfile, io, pstats
from pstats import SortKey


# To profile the code and find bottlenecks.
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


inp = open('test') if 'TESTR' in os.environ else sys.stdin


class MaxFlow:
    """
    There are the following datastructures maintained to create the residual graph
        self.V -- is the number of vertices in the Graph
        self.EdgeList -- contains the forward and reverse edges. It keeps also track of the
                         flow in the edge. The indices of the forward and reverse edges
                         differ only at the last bit.
        self.AdjList -- The graph is represented using adjcency list. The elements of the
                        adjacency list point to the indices in self.EdgeList
        self.dist -- stores the distance from source in the residual graph. This is
                     populated during BFS
        self.last[u] -- keeps track of index of the edge in self.AdjList[u] which is
                        being followed during the DFS.
        self.prev -- keeps track of the predecessor vertex during BFS
    """
    def __init__(self, V):
        self.V = V
        self.EdgeList = []
        self.AdjList = [list() for _ in range(self.V)]
        self.dist = []
        self.last = []
        self.prev = []
    
    def add_edge(self, u, v, w, directed=True):
        if u == v:
            return
        self.EdgeList.append([v,w,0])
        self.AdjList[u].append(len(self.EdgeList) - 1)
        self.EdgeList.append([u,0 if directed else w, 0])
        self.AdjList[v].append(len(self.EdgeList) - 1)
    
    def BFS(self, s, t):
        self.dist = [-1] * self.V
        self.dist[s] = 0
        self.prev = [[-1, -1] for _ in range(self.V)]
        q = deque([s])
        while len(q) > 0:
            u = q.popleft()
            if u == t:
                break

            for idx in self.AdjList[u]:
                v, cap, flow = self.EdgeList[idx]
                if cap - flow > 0 and self.dist[v] == -1:
                    self.dist[v] = self.dist[u] + 1
                    q.append(v)
                    self.prev[v] = [u, idx]
        return self.dist[t] != -1

    def DFS(self, u, t, f=inf):
        if u == t or f == 0:
            return f
        for i in range(self.last[u], len(self.AdjList[u])):
            self.last[u] = i
            v, cap, flow = self.EdgeList[self.AdjList[u][i]]
            if self.dist[v] != self.dist[u] + 1: # Ensure layered vertices
                continue
            pushed = self.DFS(v, t, min(f, cap-flow))
            if pushed != 0:
                flow += pushed
                self.EdgeList[self.AdjList[u][i]][2]= flow
                self.EdgeList[self.AdjList[u][i]^1][2] -= pushed
                return pushed
        return 0
    
    def send_one_flow(self, s, t, f=inf):
        if s == t:
            return f
        
        u, idx = self.prev[t]
        _, cap, flow = self.EdgeList[idx]
        pushed = self.send_one_flow(s, u, min(f, cap - flow))
        flow += pushed
        self.EdgeList[idx][2] = flow
        self.EdgeList[idx^1][2] -= pushed
        return pushed
    
    def edmond_karp(self, s, t):
        mf = 0 # maximum flow
        while self.BFS(s,t):
            f = self.send_one_flow(s,t)
            if f == 0:
                break
            mf += f
        return mf

    def dinic(self, s, t):
        mf = 0
        while self.BFS(s,t):
            self.last = [0] * self.V
            f = self.DFS(s,t)
            while f != 0: # While flow is not blocking, augment the flow
                mf += f
                f = self.DFS(s,t)
        return mf



#@profile
def main():
    caseno = 0
    while True:
        caseno += 1
        line = inp.readline().strip()
        if line[0] == '0':
            break
        n, m = map(int, line.split())
        monkey = [tuple(map(int, inp.readline().split())) for _ in range(n)]
        solve(n, m, monkey, caseno)

def solve(n, m, monkey, caseno):
    NUMTIMESLOTS = max([x[2] for x in monkey])
    requiredmatch = sum([x[0] for x in monkey])
    numnodes = 2 + NUMTIMESLOTS + n
    s = numnodes - 2
    t = numnodes - 1

    mf = MaxFlow(numnodes)
    for j in range(n):
        v,a,b = monkey[j]

        for i in range(a,b):
            mf.add_edge(i,j+NUMTIMESLOTS,1)

        mf.add_edge(j+NUMTIMESLOTS, t, v)
    
    for i in range(NUMTIMESLOTS):
        mf.add_edge(s,i,m)
    
    #maxmatch = mf.edmond_karp(s,t)
    maxmatch = mf.dinic(s,t)


    # The rest of the function properly formats the answer for the onlinejudge
    print(f"Case {caseno}: ", end="")
    if maxmatch < requiredmatch:
        print("No")
    else:
        print("Yes")
        for j in range(n):
            timeslots = [mf.EdgeList[x][0] for x in mf.AdjList[NUMTIMESLOTS+j] if mf.EdgeList[x][2] < 0]
            i = 0
            start = timeslots[0]
            prev = start
            output =""
            ct = 0
            for i in range(1,len(timeslots)):
                if timeslots[i] > prev + 1:
                    output += f"({start}, {prev+1}) "
                    start = timeslots[i]
                    prev = start
                    ct += 1
                else:
                    prev = timeslots[i]
            print(ct+1, output + f"({start}, {prev+1})")


if __name__ == "__main__":
    main()