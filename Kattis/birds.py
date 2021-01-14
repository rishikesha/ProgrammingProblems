#!/usr/bin/env python3

# Birds on a Wire
# https://open.kattis.com/problems/birds
#

import os, sys

f = open('test') if 'TESTR' in os.environ else sys.stdin

def main():
    l, d, n = map(int, f.readline().split())

    positions = [6-d]
    for _ in range(n):
        positions.append(int(f.readline()))
    positions.append(l-6+d)
    
    positions.sort()
    count = 0
    for i in range(1,len(positions)):
        count += (positions[i] - positions[i-1])//d -1

    print(count)



if __name__ == "__main__":
    main()