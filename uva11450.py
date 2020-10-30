#!/usr/bin/env python3
# https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2445
#


from sys import stdin

#f = open("test", 'r')
f = stdin

def solve():
    M, C = map(int, f.readline().split())
    prices = [list(map(int,f.readline().split()))[1:] for _ in range(C)]
    memo = [(M+1)* [0] for _ in range(C+1)]
    for i in range(1,C+1):
        memo[i][0] = -1

    for c in range(1,C+1):
        for m in range(1, M+1):
            s = -1 
            for p in prices[c-1]:
                s = max(s, -1 if m - p < 0  or memo[c-1][m-p] < 0 else memo[c-1][m-p] + p) # choose item corresponding to p
            memo[c][m] = s
    if memo[C][M] <= 0:
        print("no solution")
    else:
        print(memo[C][M])




if __name__ == "__main__":
    #N = int(input()) # Number of test cases
    N = int(f.readline()) # Number of test cases
    for _ in range(N):
        solve()
