#!/usr/bin/env python3
# UVA 13181 Sleeping in hostels
# https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=5092

import os, sys

INF = 100000000

def main():
    f = open(sys.argv[1]) if 'TESTR' in os.environ else sys.stdin
    #f = open("test")

    while True: 
        try:
            beds = f.readline().strip()
            #print(beds)
            if len(beds) == 0:
                break
            n = len(beds)
            dist = n * [INF]

            lastbegin = -INF
            lastend = INF
            for i in range(n):
                if beds[i] == 'X':
                    dist[i] = -1
                    lastbegin = i
                else:
                    dist[i] = min(i-lastbegin-1, dist[i])
            
                if beds[n-i-1] == 'X':
                    dist[n-i-1] = -1
                    lastend = n-i-1
                else:
                    dist[n-i-1] = min(lastend - (n-i),dist[n-i-1])
            print(max(dist))
        except EOFError:
            break

if __name__ == "__main__":
    main()

