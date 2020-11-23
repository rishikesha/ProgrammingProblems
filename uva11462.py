#!/usr/bin/env python3


if __name__ == "__main__":
    while True:
        n = int(input())
        if n == 0:
            break

        numbers = map(int, input().split())
        counts = [0] * 101
        for i in numbers:
            counts[i] += 1
        print(" ".join([str(i) for i in range(1,101) for _ in range(counts[i])]))

