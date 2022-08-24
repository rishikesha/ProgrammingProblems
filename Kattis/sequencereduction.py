
#!/usr/bin/env python3
#
# https://open.kattis.com/problems/sequencereduction
# Hints taken from official solution

import sys
import os
import heapq
from dataclasses import dataclass
from math import inf, isinf

ff = open('test') if 'TESTR' in os.environ else sys.stdin


def main():
    cost = 0
    N = int(ff.readline())
    a = [inf] + [int(ff.readline()) for _ in range(N)]
    a.append(inf)
    st = [a[0]]
    for i in range(1, N+2):
        while st[-1] <= a[i]:
            change = min(st[-2], a[i])
            if isinf(change):
                break
            cost += change
            st.pop()
        st.append(a[i])

    print(cost)


if __name__ == "__main__":
    main()
