#!/usr/bin/env python3

#
# Betting
# https://open.kattis.com/problems/betting
#

import sys, os


def main():
    f = open('test') if 'TESTR' in os.environ else sys.stdin
    n = int(f.readline())
    print(100/n)
    print(100/(100-n))

if __name__ == "__main__":
    main()
