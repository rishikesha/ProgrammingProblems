#!/usr/bin/env python3
# This program solves the following problem
# https://open.kattis.com/problems/bread
# cycles of lenghth 3 have even number of transpositions
def sortandcount(s1, s2, b, e):
    if e - b < 2:
        return 0

    ct = 0
    m = (b + e)//2
    ct += sortandcount(s2, s1, b, m)
    ct += sortandcount(s2, s1, m, e)

    i = b
    j = m
    k = b

    while i < m and j < e:
        if s2[i] <= s2[j]:
            s1[k] = s2[i]
            i += 1
        else:
            s1[k] = s2[j]
            ct += (m - i)
            j += 1
        k += 1
    while i < m:
        s1[k] = s2[i]
        i += 1
        k += 1
    while j < e:
        s1[k] = s2[j]
        j += 1
        k += 1

    #print("s1 ",s1)
    #print("s2 ",s2)
    return ct

def inversion(s):
    s1 = list(s)
    s2 = list(s)
    return sortandcount(s1, s2, 0, len(s))


def main():
    M = int(input())
    s1 = list(map(int, input().split()))
    s2 = list(map(int, input().split()))
    if (inversion(s1) - inversion(s2)) % 2 == 0:
        print("Possible")
    else:
        print("Impossible")


if __name__ == "__main__":
    main()
