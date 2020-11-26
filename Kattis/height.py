#!/usr/bin/env python3
#
# https://open.kattis.com/problems/height
#

import sys, os


def main():
    f = open(sys.argv[1]) if 'TESTR' in os.environ else sys.stdin
    n = int(f.readline())
    
    for ind in range(n):
        steps = 0
        student = list(map(int, f.readline().split()))[1:]
        for i in range(1,len(student)):
            t = student[i]
            for j in range(i):
                if t < student[j]:
                    student[j], t = t, student[j]
                    steps += 1

            student[i] = t
        print(ind+1, steps)
        



if __name__ == "__main__":
    main()