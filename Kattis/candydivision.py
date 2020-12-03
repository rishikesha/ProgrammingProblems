#!/usr/bin/env python3


def main():
    n = int(input())
    factors = set([0,n-1])
    i = 2
    while i * i <= n:
        if n % i == 0:
            factors.add(i-1)
            factors.add(n//i - 1)
        i += 1
    factors = list(factors)
    factors.sort()
    print(" ".join([str(i) for i in factors]))


if __name__ == "__main__":
    main()