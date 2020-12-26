#!/usr/bin/env python3

# Minimal Coverage UVA 10020
# https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=961
#

import os, sys

def main():
    f = open('test') if 'TESTR' in os.environ else sys.stdin
    ncases = int(f.readline())

    for _ in range(ncases):
        f.readline()
        M = int(f.readline())
        intervals = []
        while True:
            L,R = map(int, f.readline().split())
            if L==0 and R==0:
                break
            if R >= 0 and L <= M:
                intervals.append((L,R))
        intervals.sort(key=lambda x: (max(0,x[0]), -x[1]))

        possible = True
        st = []
        if len(intervals) == 0 or intervals[0][0] > 0:
            possible = False
        else:
            st = [intervals[0]]
            for i in range(1, len(intervals)):
                if st[-1][1] >= M: #Done
                    break
                Li, Ri = intervals[i]
                Lp, Rp = st[-1]
                if Li - Rp > 0:
                    possible = False
                    break
                if Ri <= Rp:
                    continue
                while len(st) > 1:
                    Lp, Rp = st[-1]
                    Lpp, Rpp = st[-2]
                    if Li <= Rpp:
                        st.pop()
                    else:
                        break
                st.append((Li,Ri))
            if st[-1][1] < M:
                possible = False
        if possible:
            print(len(st))
            for L, R in st:
                print(L,R)
        else:
            print(0)
        print()


        

if __name__ == "__main__":
    main()