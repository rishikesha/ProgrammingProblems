#!/usr/bin/env python3
#
# 10887 Concatenation of languages
# https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=20&page=show_problem&problem=1828
#

import sys, os

def main():
    f = open(sys.argv[1]) if 'TESTR' in os.environ else sys.stdin
    ncases = int(f.readline())
    for caseno in range(ncases):
        M, N = map(int, f.readline().split())
        L1 = [f.readline().strip() for _ in range(M)]
        L3 = set()
        for _ in range(N):
            w2 = f.readline().strip()
            for w1 in L1:
                L3.add(w1+w2)
        print(f"Case {caseno + 1}: {len(L3)}")

if __name__ == "__main__":
    main()