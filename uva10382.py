#!/usr/bin/env python3

# Watering Grass
# https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=15&page=show_problem&problem=1323
#
#

import os, sys

def main():
    f = open('test') if 'TESTR' in os.environ else sys.stdin
    i = 0
    while True:
        i += 1
        line = f.readline()
        if len(line) < 2:
            return
        n, l, w = map(int, line.split())
        intervals = []
        for _ in range(n):
            c, r = map(int, f.readline().split())
            intrvl = convertToInterval(c, r, w)
            if intrvl:
                intervals.append(intrvl)
        print(findMinimum(intervals, l))

def convertToInterval(c, r, w):
    if 2*r <= w:
        return ()
    from math import sqrt
    h = sqrt(r*r - w * w/4)
    return (c-h, c+h)
    
def findMinimum(intervals, l):
    intervals.sort(key=lambda x : (x[0],-x[1]))
    if len(intervals) == 0 or intervals[0][0] > 0: # return -1 if first sprinkler cannot cover the left end
        return -1

    intervals = [((0,y[1]) if y[0] <=0 else y)  for y in intervals]

    st = [(0,0)]

    for i in range(len(intervals)):
        x1, y1 = intervals[i]
        x2, y2 = st[-1]
        if y2 < x1:
            return -1
        if y1 > y2:
            while len(st) > 1:
                x2, y2 = st[-1]
                x3, y3 = st[-2]
                if y3 >= x1:
                    st.pop()
                else:
                    break
            st.append((x1,y1))
        if y1 >= l:
            break
    if st[-1][1] < l:
        return -1
    else:
        return len(st) - 1
    
if __name__ == "__main__":
    main()