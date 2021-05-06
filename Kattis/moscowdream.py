#!/usr/bin/env python3

import os, sys

# Moscow Dream
# https://open.kattis.com/problems/moscowdream
#
# Everything is obvious except that we have to check
# there are adequate number of problems, and the number
# of problems is at least 3
#

if __name__ == "__main__":
    f = open(sys.argv[1]) if "TESTR" in os.environ  else sys.stdin
    a,b,c,n = map(int, f.readline().split())

    if a > 0 and b > 0 and c > 0 and a+b+c >= n and n >= 3:
        print("YES\n")
    else:
        print("NO\n")

