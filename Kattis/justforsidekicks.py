#!/usr/bin/env python3

# Just for Sidekicks
# https://open.kattis.com/problems/justforsidekicks
# The idea of using 6 Fenwick trees is from the website
# https://cpbook.net
# It would have taken me much longer to solve the problem
# without that hint.


import sys, os

f = open('test') if 'TESTR' in os.environ else sys.stdin

class FenwickTree:
    """
    Fenwick Tree datastructure. add(k,x) and cumsum(k) and the main
    functions. everything else is implemented on top of these.
    """
    def __init__(self, N):
        self.N = N
        self._arr = (N+1) * [0]

    def add(self, k, x):
        """
        add x to position k of the array
        """
        if k < 1 or k > self.N:
            raise IndexError(f"{k} is not within 1 and {self.N}")

        while k <= self.N:
            self._arr[k] += x
            k += (k & (-k))

    def cumsum(self, k):
        """
        Cummulative sum for range 1..k.
        """
        if k < 1 or k > self.N:
            raise IndexError(f"{k} is not within 1 and {self.N}")
        ans = 0
        while k > 0:
            ans += self._arr[k]
            k -= (k & (-k))
        return ans
    
    def rangesum(self, i,j):
        """
        sum of elements i..j (both inclusive)
        """
        return self.cumsum(j) - (0 if i == 1 else self.cumsum(i-1))

    def change(self, i, x):
        prev_value = self.rangesum(i,i)
        self.add(i, x-prev_value)

def test():
    """
    This was used only for debugging. I am leaving this intact.
    """
    ft = FenwickTree(10)
    ft.add(3,30)
    ft.add(5,50)
    ft.add(4,40)
    ft.change(4,400)
    ft.add(6,60)
    ft.add(7,60)
    a=ft.cumsum(6)
    b = ft.cumsum(10)
    b

def main():
    N, Q = map(int,f.readline().split())
    V = [0] + list(map(int, f.readline().split()))
    P =  "0" +f.readline().strip()
    P = list(map(int,list(P)))
    numgems = len(P) - 1


    ft = [FenwickTree(1)] + [FenwickTree(numgems) for _ in range(6)]


    for i in range(1,len(P)):
        g = P[i]
        ft[g].add(i, 1)
    
    for _ in range(Q):
        q1, q2, q3 = map(int, f.readline().split())
        if q1 == 1:
            k,p = q2,q3
            ft[p].change(k,1)
            ft[P[k]].change(k,0)
            P[k]=p
        elif q1 == 2:
            i,v = q2,q3
            V[i] = v
        else:
            l, r = q2, q3
            value = sum([V[i]* ft[i].rangesum(l,r) for i in range(1,7)])
            print(value)



if __name__ == "__main__":
    main()
