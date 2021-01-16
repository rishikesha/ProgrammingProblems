#!/usr/bin/env python3

# Verify This, Your Majesty
# https://open.kattis.com/problems/queens
#

import sys, os

f = open('test') if 'TESTR' in os.environ else sys.stdin

def main():
    n = int(f.readline())
    row = n*[False]
    col = n*[False]
    rightdi = (2*n-1) *[False] # Right diagonal
    leftdi = (2*n-1) *[False] # Left diagonal

    for _ in range(n):
        r, c = map(int, f.readline().split())
        # Check if there is another queen attacking the row, column, right diagonal or left diagonal
        if row[r] or col[c] or rightdi[c-r+ n-1] or leftdi[r+c]:
            print("INCORRECT")
            return
        row[r]=col[c]=rightdi[c-r+ n-1]=leftdi[r+c] = True
    print("CORRECT")


if __name__ == "__main__":
    main()
