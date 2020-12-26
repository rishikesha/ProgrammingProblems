#!/usr/bin/env python3

#
#
#Electric Bill
# https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=243&page=show_problem&problem=3342
#

import os, sys, bisect

def computeBill(n):
    if n <= 100:
        return 2 * n
    elif n <= 10000:
        return 3 * (n - 100) + 200
    elif n <= 1000000:
        return 5 * (n - 10000) + 29900
    else:
        return 7 * (n - 1000000) + 4979900

def consumption(bill):
    if bill >= 4979900:
        return 1000000 + (bill - 4979900)// 7
    elif bill >= 29900:
        return 10000 + (bill - 29900) // 5
    elif bill >= 200:
        return 100 + (bill - 200) // 3
    else:
        return bill // 2

def main():
    f = open('test') if 'TESTR' in os.environ else sys.stdin
    while True:
        A, B = map(int, f.readline().split())
        if A == 0 and B == 0:
            return
        totalConsumption = consumption(A)

        lo = 0
        hi = totalConsumption

        while True:
            mid = (lo + hi)//2
            mybill = computeBill(mid)
            hisbill = computeBill(totalConsumption - mid)
            if hisbill - mybill == B:
                print(mybill)
                break
            elif hisbill - mybill < B:
                hi = mid - 1
            else:
                lo = mid + 1


if __name__ == "__main__":
    main()


