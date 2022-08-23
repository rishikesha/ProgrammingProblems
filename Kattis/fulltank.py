#!/usr/bin/env python3
#
# https://open.kattis.com/problems/fulltank
# The solution uses Dijkstra's algorithm.
# The nodes of the graph in consideration are pairs (city, fuel).
# The list of lists "cityfuel" records the minimum cost to reach
# that state. It is also used to avoid searching through the
# same states.
#

import sys
import os
import heapq
from dataclasses import dataclass


ff = open('test') if 'TESTR' in os.environ else sys.stdin


@dataclass
class CarState:
    city: int
    fuel: int
    cost: int

    def __lt__(self, other):
        return self.cost < other.cost


def main():
    n, m = map(int, ff.readline().split())
    p = list(map(int, ff.readline().split()))
    G = [[] for _ in range(n)]
    for _ in range(m):
        u, v, d = map(int, ff.readline().split())
        G[u].append((v, d))
        G[v].append((u, d))

    nqueries = int(ff.readline())

    while nqueries > 0:
        nqueries -= 1
        cityfuel = [[-1 for _ in range(101)] for _ in range(1001)]
        c, s, e = map(int, ff.readline().split())
        pq = [CarState(s, 0, 0)]

        notFound = True
        while pq:
            cs = heapq.heappop(pq)
            city = cs.city
            fuel = cs.fuel
            cost = cs.cost
            if city == e:
                print(cost)
                notFound = False
                break

            if cityfuel[city][fuel] >= 0:
                continue
            cityfuel[city][fuel] = cost

            if fuel < c:
                heapq.heappush(pq, CarState(city, fuel+1, cost+p[city]))

            for (v, w) in G[city]:
                if w <= fuel and cityfuel[v][fuel - w] < 0:
                    heapq.heappush(pq, CarState(v, fuel - w, cost))
        if notFound:
            print("impossible")


if __name__ == "__main__":
    main()
