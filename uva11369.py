#!/usr/bin/env python3

# 11369 Shopaholic
# https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=25&page=show_problem&problem=2354

import os, sys

def main():
    f = open('test') if 'TESTR' in os.environ else sys.stdin
    ncases = int(f.readline())
    for _ in range(ncases):
        n = int(f.readline())
        items = list(map(int, f.readline().split()))
        items.sort(key=lambda x: -x)
        discount = sum(items[2::3])
        print(discount)

if __name__ == "__main__":
    main()