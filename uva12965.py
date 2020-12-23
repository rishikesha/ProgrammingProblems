#!/usr/bin/env python3

# 12965 Angry Birds
# https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=862&page=show_problem&problem=4844
#

import os, sys, bisect


def main():
    f = open('test') if 'TESTR' in os.environ else sys.stdin
    ntestcases = int(f.readline())
    for _ in range(ntestcases):
        P, C = map(int, f.readline().split())
        producer = list(map(int, f.readline().split()))
        consumer = list(map(int, f.readline().split()))

        testprices = [0] + consumer + producer # Will check only the 20000 prices
        testprices.sort()

        consumer.sort()
        producer.sort()

        bestprice = 0
        numangry  = 10**9
        for p in testprices:
            i = bisect.bisect_left(consumer, p)
            angry = i
            j = bisect.bisect(producer, p)
            angry += P - j
            if angry < numangry:
                bestprice = p
                numangry = angry
        if numangry == 10**9:
            numangry = 0
        print(bestprice, numangry)


if __name__ == "__main__":
    main()

