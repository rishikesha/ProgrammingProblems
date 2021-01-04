#!/usr/bin/env python3

# Minimum Spanning Tree
# https://open.kattis.com/problems/minspantree
# Does not pass test. Can't find why
# I am commiting it to github for the implementation of priority with ability
# to change weight


import os, sys, heapq

class PriorityQueue:
    class Element:
        def __init__(self, item, weight):
            self.item = item
            self.weight = weight
        
        def __lt__(self, other):
            return self.weight < other.weight

    def __init__(self):
        self.pq = [None]
        self.location = {}

    def left(self, n):
        return  (n << 1)

    def right(self, n):
        return  (n << 1) + 1

    def parent(self, n):
        return (n >> 1)

    def length(self):
        return len(self.pq) - 1

    def push(self, item, weight):
        e = self.Element(item, weight)
        self.pq.append(e)
        self.location[item] = self.length()
        n = self.length()
        self.float(n)

    def swap(self, p, n):
            self.location[self.pq[n].item] = p
            self.location[self.pq[p].item] = n
            self.pq[n], self.pq[p] = self.pq[p], self.pq[n]

    def float(self, n):
        if n == 1:
            return
        p = self.parent(n)
        if self.pq[n] < self.pq[p]:
            self.swap(p,n)
            self.float(p)

    def sink(self, n):
        l = self.left(n)
        if l > self.length():
            return

        r = self.right(n)
        d = l
        if r <= self.length():
            d = l if self.pq[l] < self.pq[r] else r
        if self.pq[d] < self.pq[n]:
            self.swap(d,n)
            self.sink(d)
        

    def pop(self):
        n = self.length()
        self.swap(1,n)
        ret = self.pq.pop()
        self.sink(1)
        del self.location[ret.item]
        return (ret.item, ret.weight)

    def changeWeight(self, item, w):
        i = self.location[item]
        oldweight = self.pq[i].weight
        self.pq[i].weight = w
        if oldweight > w:
            self.float(i)
        elif oldweight < w:
            self.sink(i)
    
    def weight(self, item):
        n = self.location[item]
        return self.pq[n].weight

    def empty(self):
        return self.length() == 0
    

def main():
    f = open('test') if 'TESTR' in os.environ else sys.stdin
    while True:
        n, m = map(int, f.readline().split())
        if n == 0 and m == 0:
            break

        G = [[] for _ in range(n)]

        for _ in range(m):
            u, v, w = map(int, f.readline().split())
            G[u].append((v,w))
            G[v].append((u,w))


        pq = PriorityQueue()
        pq.push(0,0)
        for i in range(1, n):
            pq.push(i,float('inf'))

        found = set()
        cost = 0
        pred = [None for _ in range(n)]
        while not pq.empty():
            i, w = pq.pop()
            cost += w
            found.add(i)
            for (v,w) in G[i]:
                if v not in found and pq.weight(v) > w:
                    pred[v] = i
                    pq.changeWeight(v,w)
        
        if cost > 10**9:
            print("Impossible")
        else:
            print(cost) 
            for i in range(1,n):
                print(*sorted([i,pred[i]]))
        
        



if __name__ == "__main__":
    main()