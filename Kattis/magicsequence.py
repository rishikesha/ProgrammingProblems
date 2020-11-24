#!/usr/bin/env python3
# This solves 
# https://open.kattis.com/problems/magicsequence

import os
import sys

def simpleSort(S, X, Y):
    S.sort()
    V = 0
    for i in range(len(S)):
        V = (V * X + S[i]) % Y
    return V

def countingSort(S, X, Y):
    R = 1000001 *[0]
    for i in S:
        R[i] += 1
    
    V = 0
    for i in range(1000001):
        for _ in range(R[i]):
            V = (V * X + i) % Y
    return V

def radixSort(S, X, Y):
    """
    This is needed to pass the hardest tests. 
    """
    partition = [0,len(S)]
    for shift in range(31,-1,-1):
        #print("came 1")
        #print(partition)
        newpartpoints = []
        for p in range(len(partition)-1):
            b = partition[p]
            e = partition[p+1]
            result = [[], []]
            mask = (1 << shift)
            for i in range(b,e):
                if (S[i] & mask):
                    result[1].append(S[i])
                else:
                    result[0].append(S[i])
            
            i = b
            for x in result[0]:
                S[i] = x
                i += 1
            if i != e and i != b:
                newpartpoints.append(i)
            for x in result[1]:
                S[i] = x
                i += 1
        partition = partition + newpartpoints
        partition.sort() # This is maximum size 32 so use the system sort

    V = 0
    for Ri in S:
        V = (V * X + Ri) % Y
    
    return V


    
    
            
            







def main():
    f = None
    if 'TESTRISHI' in os.environ:
        f = open('test')
    else:
        f = sys.stdin
    TC = int(f.readline())

    for _ in range(TC):
        N = int(f.readline())
        A,B,C = map(int, f.readline().split())
        X, Y = map(int, f.readline().split())

        S = N * [0]
        S[0] = A
        for i in range(1,N):
            S[i] = (S[i-1] * B + A) % C
        
        #print(countingSort(S, X, Y))
        #print(radixSort(S, X, Y))
        print(simpleSort(S, X, Y))
        



if __name__ == "__main__":
    main()