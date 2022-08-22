#!/usr/bin/env python3
# The Clock
# https://open.kattis.com/problems/klockan2
# This took me longer that it should have.

def compute_angle(h, m):
    # Use the each minute is 6 degrees of angle
    #anglem = m * 6
    #angleh = h * 30 + 5 * m/60 * 6

    # Multiplied by 10 as required by the problem statement
    # This also ensures everything is an integer
    anglem = m * 60
    angleh = h * 300 + 5 * m

    ans = anglem - angleh
    if ans < 0:
        ans += 3600

    return ans


def construct_table():
    result = [0 for _ in range(3600)] # sparse since only 720 spots are needed

    for h in range(12):
        for m in range(60):
            result[compute_angle(h, m)] = (h, m)
    return result


def main():
    pass


if __name__ == "__main__":
    a = construct_table()
    n = int(input())
    h, m = a[n]
    print(f"{h:02}:{m:02}")

    # main()
