#!/usr/bin/env python3

#
# Guessing Game
# https://open.kattis.com/problems/guessinggame
# This solution does slight more than what the question asks. 
# It also verifies if the all the answers are consistent with 
# the previous answers.

import sys, os
from math import inf


def main():
    f = open('test') if 'TESTR' in os.environ else sys.stdin

    left = -inf
    right = inf
    honest = True

    while True:
        n = int(f.readline())
        if n == 0:
            break

        response = f.readline().strip()

        if response == "too low":
            if n >= right:
                honest = False
            left  = max(left, n+1)
        elif response == "too high":
            if n <= left:
                honest = False
            right = min(right, n-1)

        elif response == "right on":
            if left > n or right < n:
                honest = False
            if honest:
                print("Stan may be honest")
            else:
                print("Stan is dishonest")
            # reset left, right, and honest for the next set of answers
            left = -inf
            right = inf
            honest = True



if __name__ == "__main__":
    main()
