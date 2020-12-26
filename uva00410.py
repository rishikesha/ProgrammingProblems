#!/usr/bin/env python3


# Station Balance
# https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=657&page=show_problem&problem=351
#
import os, sys

def main():
    f = open('test') if 'TESTR' in os.environ else sys.stdin


    caseno = 0
    while True:
        line = f.readline()
        if len(line) < 2:
            return
        caseno += 1
        C, S = map(int, line.split())
        weight = list(map(int, f.readline().split()))
        weight.sort(reverse=True)
        meanweight = sum(weight)/C
        chamber = [[] for _ in range(C)]

        for i in range(S):
            if i < C:
                chamber[i].append(weight[i])
            else:
                chamber[2*C - i -1].append(weight[i])
        
        chamberweights = list(map(sum, chamber))
        imbalance = sum(map(lambda x: abs(meanweight -x), chamberweights))

        print(f"Set #{caseno}")
        for i in range(C):
            print(f" {i}: " + " ".join(map(str, chamber[i])))
        print(f"IMBALANCE = {imbalance:0.5f}\n")


if __name__ == "__main__":
    main()


        
        

