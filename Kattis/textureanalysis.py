#!/usr/bin/env python3

#
# Texture Analysis
# https://open.kattis.com/problems/textureanalysis
# 

import sys, os


def main():
    f = open('test') if 'TESTR' in os.environ else sys.stdin

    lineno = 0
    while True:
        pattern = f.readline().strip()
        if pattern == "END":
            break

        lineno += 1
        even = True
        spacingnotset = True
        firstspacing = 0
        currentspacing = 0
        for c in pattern[1:]:
            if c == ".":
                currentspacing += 1
            else:
                if spacingnotset:
                    firstspacing = currentspacing
                    spacingnotset = False
                if firstspacing != currentspacing:
                    even = False
                currentspacing = 0
        print(f"{lineno} " + ("EVEN" if even else "NOT EVEN"))

def main2():
    f = open('test') if 'TESTR' in os.environ else sys.stdin

    lineno = 0
    while True:
        lineno += 1
        pattern = f.readline().strip()
        if pattern == "END":
            break
        pattern = pattern[1:-1] # remove leading and trailing "*"
        lst = list(map(len, pattern.split("*")))
        even = not lst or all(map(lambda l: l == lst[0], lst))
        if even:
            print(f"{lineno} EVEN")
        else:
            print(f"{lineno} NOT EVEN")










if __name__ == "__main__":
    main2()

