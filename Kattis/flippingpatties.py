#!/usr/bin/env python3

# Flipping Patties
# https://open.kattis.com/problems/flippingpatties
#
#

import os, sys
from math import ceil
from collections import Counter

f = open('test') if 'TESTR' in os.environ else sys.stdin

def main():
    n = int(f.readline())
    
    actions = [0]*45000 # Can use Counter() with line 24 replaced by m = max(actions.values())
    for _ in range(n):
        di, ti = map(int, f.readline().split())
        actions[ti] += 1 # remove patty
        actions[ti-di] += 1 # flip patty
        actions[ti-2*di] += 1 # put patty on grill
    m = max(actions)
    print(m//2 + m %2) # same as ceil(m/2)



if __name__ == "__main__":
    main()