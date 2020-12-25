#!/usr/bin/env python3

# Expeditious Cubing
# https://open.kattis.com/problems/expeditiouscubing
# The logic is easy but working in floating points will not work.
# Converting to int works, but the corner cases are easy to miss.

import sys, os, bisect


def main():
    f = open('test') if 'TESTR' in os.environ else sys.stdin
    scores = f.readline().split()
    scores = map(lambda x: x.replace(".", ""), scores)
    scores = list(map(int, scores))
    scores.sort()
    target = f.readline().strip()
    target = int(target.replace('.',''))
    target = target 

    if sum(scores[1:]) <= 3*target:
        print('infinite')
    elif sum(scores[0:-1]) > 3*target:
        print('impossible')
    else:
        result = 3 * target - (scores[1]  + scores[2])
        result = result
        n = result//100
        n = str(n)
        r = result % 100
        lpad =  ""
        if r < 10:
            lpad = "0"
        r = lpad + str(r)
        print(n + "." + r)

def findscore(scores, target):
    lo = scores[0]
    hi = scores[-1]
    while abs(lo - hi) > 10:
        mid = (lo + hi)//2
        newscores = scores + [mid]
        newscores.sort()
        nscore = sum(newscores[1:-1])/3
        if nscore > target:
            hi = mid
        else:
            lo = mid
    return lo





    


if __name__ == "__main__":
    main()