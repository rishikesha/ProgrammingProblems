#!/usr/bin/env python3

#
# UVA 12108
#  Extraordinarily Tired Students
# https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=243&page=show_problem&problem=3260


import sys, os

def main():
    f = open(sys.argv[1]) if 'TESTR' in os.environ else sys.stdin
    #f = open("test")
    caseno = 1
    while True:
        n = int(f.readline())
        if n == 0:
            break
        state = [] # Called c in the problem statement
        A = []
        B = []
        for _ in range(n):
            a,b,c = map(int, f.readline().split())
            A.append(a)
            B.append(b)
            state.append(c)

        visited = set()
        visited.add(tuple(state))
        t = 1

        while True:
            countsleeping = nextstate(A, B, state)
            if countsleeping == 0:
                break
            tup = tuple(state)
            if tup in visited:
                t = -1
                break
            visited.add(tup)
            t += 1
        print(f"Case {caseno}:", t)
        caseno += 1




def nextstate(A, B, state):
    n = len(A)
    countsleeping = sum([state[i] > A[i] for i in range(n)])

    for i in range(n):
        if state[i] == A[i]:
            if countsleeping > n//2:
                state[i] += 1
            else:
                state[i] = 1
        elif state[i] == A[i] + B[i]:
            state[i] = 1
        else:
            state[i] += 1
    return countsleeping



if __name__ == "__main__":
    main()