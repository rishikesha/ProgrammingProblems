#!/usr/bin/env python3

#
# Suffix Sorting
# https://open.kattis.com/problems/suffixsorting
# I used the algorithm from https://cp-algorithms.com/string/suffix-array.html
# It is not O(nlogn). It is O(n (log n)^2). This does not pass the
# large string test. A c++ version of this algorithm should pass the test. I 
# will replace the library version of sort to bucket sort and see if it
# passes the large string test.
# 

import sys, os

def suffixsort(s):
    s = s + '\0' # add a character which is smaller than every other
    n = len(s)

    p = list(range(n))
    p.sort(key = lambda i : s[i])

    c = [0 for _ in range(n)]
    classes = 0

    #c[p[0]] = 0
    for i in range(1, n):
        if s[p[i-1]] != s[p[i]]:
            classes += 1
        c[p[i]] = classes

    h = 0
    while (1 << h) < n:
        hh = 1 << h
        h += 1

        np = list(range(n))

        np.sort(key = lambda i : (c[i], c[(i+hh) % n]))

        p = np

        classes = 0
        c[p[0]] = 0

        for i in range(1,n):
            curr = (c[p[i]], c[(p[i] + hh) % n])
            prev = (c[p[i-1]], c[(p[i-1] + hh) % n])
            if prev != curr:
                classes += 1
            c[p[i]] = classes



    return p
    






def main():
    f = open('test') if 'TESTR' in os.environ else sys.stdin
    
    while True:
        s = f.readline().strip()
        if len(s) == 0:
            break

        queries = map(int, f.readline().split())

        ans = ""
        next(queries)
        p = suffixsort(s)
        for  i in queries:
            ans += (str(p[i+1]) + " ")

        print(ans)








if __name__ == "__main__":
    main()

