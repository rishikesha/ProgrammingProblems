#!/usr/bin/env python3
#
# Sort of sorting
# https://open.kattis.com/problems/sortofsorting

import sys, os

def main():
    f =  open(sys.argv[1]) if 'TESTR' in os.environ else sys.stdin
    while True:
        n = int(f.readline())
        if n == 0:
            break
        names = [f.readline().strip() for _ in range(n)]
        names.sort(key=lambda x : x[:2])
        for name in names:
            print(name)
        print()



if __name__ == "__main__":
    main()