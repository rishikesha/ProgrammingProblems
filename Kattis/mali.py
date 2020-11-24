#!/usr/bin/env python3
# https://open.kattis.com/problems/mali
# Uses counting sort

import  os, sys



def main():
    f = open(sys.argv[1]) if 'TESTR' in os.environ else sys.stdin
    #f = open('test')
    N = int(f.readline())
    A = 101 * [0]
    B = 101 * [0]
    for _ in range(N):
        a, b = map(int, f.readline().split())
        A[a] += 1
        B[b] += 1

        At = A[:] # A copy of A and B which we can modify
        Bt = B[:]

        ans = 0

        i = 1
        j = 100

        while i != 100 or j != 1:
            while At[i] == 0 and i < 100:
                i += 1
            while Bt[j] == 0 and j > 1:
                j -= 1
            
            if At[i] > 0 and Bt[j] > 0:
                ans = max(ans, i+j)
            seen = min(At[i], Bt[j])
            At[i] -= seen
            Bt[j] -= seen
        print(ans)
    
if __name__ == "__main__":
    main()