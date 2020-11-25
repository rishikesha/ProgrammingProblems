#!/usr/bin/env python3
# https://open.kattis.com/problems/evenup

import os
import sys
from sys import argv

def main():
    f = open(argv[1]) if 'TESTR' in os.environ else sys.stdin
    _ = int(f.readline()) 
    card1 = list(map(int, f.readline().split()))
    card2 = []

    while len(card1) > 0:
        if len(card2) > 0  and (card1[-1] + card2[-1]) % 2 == 0:
            card1.pop()
            card2.pop()
        else:
            card2.append(card1[-1])
            card1.pop()
    print(len(card2))



if __name__ == "__main__":
    main()