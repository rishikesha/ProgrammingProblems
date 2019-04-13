#!/usr/bin/env python3

class Contestant:
    def __init__

from collections import defaultdict, Counter

if __name__ == "__main__":
    n = int(input())
    input()
    while n > 0:
        n -= 1
        data = []

        contprob = [[False] * 10 for i in range(101)]
        penalty = [0] * 101



        while True:
            a = input()
            if not a:
                break;

            ctnt, prob, time, result = a.split()
            ctnt, prob, time = map(int, ctnt, prob, time)
            if result == "C" and not solved[ctnt][prob]:
                penalty[ctnt] += time
            elif result == "I" and not solved[ctnt][prob]:
                penalty[ctnt] += 20

        answer = [(sum(contprob[ctnt]), penalty[ctnt], ctnt) for ctnt in range(1,101) if sum(contprob[ctnt]) != 0]
        answer = sorted(answer, key = lambda x : (-x[0], x[1], x[2]))



