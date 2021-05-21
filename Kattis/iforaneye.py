#!/usr/bin/env python3

# An I for an Eye
# https://open.kattis.com/problems/iforaneye
#
# There are two solutions to this problem. One uses regular expressions.
# contractWord and contractWord2 are the relevant functions.

import sys, os, re, string
from typing import Tuple, Dict

f = open('test') if 'TESTR' in os.environ else sys.stdin

e = re.compile("at|and|one|won|too?|two|fou?r|be[ae]?|se[ae]|eye|o(h|we)|are|you|why")

lookuptable = {
    "at": "@",
    "and": "&",
    "one" : "1",
    "won" : "1",
    "to" : "2",
    "too" : "2",
    "two" : "2",
    "for" : "4",
    "four" : "4",
    "bea" : 'b',
    "be" : 'b',
    "bee" : 'b',
    "sea" : 'c',
    "see" : 'c',
    "eye" : 'i',
    "oh" : 'o',
    "owe" : 'o',
    "are" : 'r',
    "you" : "u",
    "why" : 'y'
}

def getvalue(d : Dict[str, str], k : str) -> str:
    if k in d.keys():
        return d[k]
    return k


def findLongestMatch(word : str) -> int:
    for i in range(len(word),1,-1):
        if word[:i].lower() in lookuptable.keys():
            return i
    return 1


def contractWord(word : str) -> str:
    result = ""
    while word != "":
        i = findLongestMatch(word)
        w = getvalue(lookuptable, word[0:i].lower())
        if word[0] in string.ascii_uppercase:
            w = w.capitalize()
        result += w
        word = word[i:]
    return result

def contractWord2(word: str) -> str:
    result = ""
    while word != "":
        m = e.match(word.lower())
        if m:
            w = lookuptable[word[0:m.end()].lower()]
            if word[0] in string.ascii_uppercase:
                w = w[0].upper() + w[1:]
            result += w
            word = word[m.end():]
        else:
            result += word[0]
            word = word[1:]
    return result


if __name__ == "__main__":
    n = int(f.readline())
    for _ in range(n):
        words = f.readline().split()
        print(" ".join(map(contractWord, words)))
        #print(" ".join(map(contractWord2, words)))
