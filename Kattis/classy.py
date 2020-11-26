#!/usr/bin/env python3
#
# Classy
# https://open.kattis.com/problems/classy

import sys, os
from collections import namedtuple
namecls = namedtuple("namecls", ["name", "cls"])

#partition = "".join(["="] * 30)
partition = "=============================="

def main():
    f = open(sys.argv[1]) if 'TESTR' in os.environ else sys.stdin
    T = int(f.readline())

    def tonumber(cls):
        cls = cls.strip()
        if cls == 'upper':
            return 0
        elif cls == 'middle':
            return 1
        elif cls == 'lower':
            return 2

    for _ in range(T):
        n = int(f.readline())
        arr = []
        for _ in range(n):
            name, cls = f.readline().strip().split(":") # split name and class
            cls = cls.strip().split()[0] # get rid of the word class
            cls = cls.split("-") # split different parts of class string
            cls = list(map(tonumber, cls)) # convert class to number for comparision
            cls.reverse() # class is ordered in reverse lexicographical order
            cls = cls + ([1] * (10 - len(cls))) # pad so that all equivalent classes have same cls string
            arr.append(namecls(name=name, cls=tuple(cls))) # sort by cls first and then by name
        arr.sort(key=lambda x: (x.cls,x.name))
        for x in arr:
            print(x.name)
        print(partition)




if __name__ == "__main__":
    main()