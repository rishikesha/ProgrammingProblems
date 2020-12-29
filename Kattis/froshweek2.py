#!/usr/bin/env python3

#
# Frosh Week
# https://open.kattis.com/problems/froshweek2
#

import sys, os

def main():
    f = open('test') if 'TESTR' in os.environ else sys.stdin
    n, m = map(int, f.readline().split())
    task = list(map(int, f.readline().split()))
    quietinterval = list(map(int, f.readline().split()))
    task.sort()
    quietinterval.sort()
    answer = 0
    i = 0
    j = 0
    while i < n and j < m:
        if quietinterval[j] >= task[i]:
            answer += 1
            j += 1
            i += 1
        else:
            j += 1
    print(answer)


if __name__ == "__main__":
    main()