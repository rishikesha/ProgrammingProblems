#!/usr/bin/env python3

if __name__ == "__main__":
    while True:
        B,N = map(int, input().split())
        if B == 0:
            break
        R = list(map(int, input().split()))
        D = []
        for _ in range(N):
            D.append(list(map(int, input().split())))
        X = [0] * B

        for d in D:
            R[d[0]-1] -= d[2]
            R[d[1]-1] += d[2]

        if all(map(lambda x: x>=0,R)):
            print("S")
        else:
            print("N")

