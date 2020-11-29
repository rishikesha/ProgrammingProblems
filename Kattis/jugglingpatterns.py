#!/usr/bin/env python3
#
# Juggling Patterns
# https://open.kattis.com/problems/jugglingpatterns


import os,sys
from itertools import cycle
import heapq
from math import gcd


def main():
    f = open(sys.argv[1]) if 'TESTR' in os.environ else sys.stdin
    while True:
        s = f.readline().strip()
        if len(s) == 0:
            break
        checkvalid(s)

def checkvalid(s):
    si = list(map(int, s))
    sIter = cycle(si)

    numBalls, rem = divmod(sum(si), len(si)) 

    if rem != 0:
        print(f"{s}: invalid # of balls")
        return
    
    if numBalls == 0:
        print(f"{s}: valid with {numBalls} balls")
        return
    
    
    t = 0
    #maxbeat = max(si)
    pq = []

    # Make sure all the balls are in play, the steady state is achieved
    # by running for at least 2 cycles
    #for i in range(-(2 * (len(si)+max(si))),1):
    for i in range(-(2 * (len(si)+9)),1):
        nxt = next(sIter)
        if nxt > 0:
            heapq.heappush(pq, nxt+i)
    # Remove all catches occuring at or before time 0
    while len(pq) > 0 and pq[0] <= 0:
        heapq.heappop(pq)


    # Simulate at least 2 more cycles
    #for _ in range(2*(len(si)+max(si))):
    for _ in range(2*(len(si)+ 9)):
        t += 1
        nxt = next(sIter)

        # Catch and throw the ball
        if nxt > 0: # ball is thrown, make sure ball has come
            if len(pq) > 0 and t == pq[0]:
                heapq.heappop(pq)
                heapq.heappush(pq, nxt + t)
            else: # ball has not come or come at wrong time
                print(f"{s}: invalid pattern")
                return
        else: #nxt == 0, hence no ball is thrown
            if len(pq) > 0 and t >= pq[0]: # if there is ball waiting to be thrown
                print(f"{s}: invalid pattern")
                return

    print(f"{s}: valid with {numBalls} balls")






if __name__ == "__main__":
    main()