#!/usr/bin/env python3
#
# Bard
# https://open.kattis.com/problems/bard
#
#

import sys
import os

ff = open('test') if 'TESTR' in os.environ else sys.stdin


def main():
    N = int(ff.readline())
    nEvenings = int(ff.readline())

    index = 0
    songs = [set() for _ in range(N+1)]

    for _ in range(nEvenings):
        participants = list(map(int, ff.readline().split()))[1:]
        if 1 in participants:
            index += 1
            for i in participants:
                songs[i].add(index)
        else:
            acc = set()
            for i in participants:
                acc.update(songs[i])
            for i in participants:
                songs[i] = acc.copy()
    for i in range(1, N+1):
        if len(songs[i]) == len(songs[1]):
            print(i)


if __name__ == "__main__":
    main()
