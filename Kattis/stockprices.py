#!/usr/bin/env python3

# Stock Prices
# https://open.kattis.com/problems/stockprices
# This gives WA in one out of two tests, but I am unable to figure out from
# the description which condition is violated since the failing test is hidden.
#
# I assumed that the highest bid gets fulfilled first at the lowest ask in the solution below.
# Assuming  first come first served (given that conditions are satisfied) does
# not work either. 

import os, sys, heapq


class Buy:
    def __init__(self, bprice, quantity):
        self.bprice = bprice
        self.quantity = quantity
    
    def __lt__(self, other):
        return self.bprice > other.bprice

class Sell:
    def __init__(self, sprice, quantity):
        self.sprice = sprice
        self.quantity = quantity
    
    def __lt__(self, other):
        return self.sprice < other.sprice


def main():
    f = open('test') if 'TESTR' in os.environ else sys.stdin
    #f = open('test')
    numcases = int(f.readline())
    for _ in range(numcases):
        n = int(f.readline())
        bidq = []
        askq = [] 
        
        for _ in range(n):
            command = f.readline().split()
            action = command[0]
            num = int(command[1])
            val = int(command[4])
            shareprice = -1


            if action == "sell":
                heapq.heappush(askq, Sell(val, num))
            elif action == "buy":
                heapq.heappush(bidq, Buy(val, num))
            
            while len(askq) > 0 and len(bidq) > 0 and askq[0].sprice <= bidq[0].bprice:
                buy = heapq.heappop(bidq)
                sell = heapq.heappop(askq)
                quantity = min(buy.quantity, sell.quantity)
                shareprice = sell.sprice
                buy.quantity -= quantity
                sell.quantity -= quantity

                if buy.quantity > 0:
                    heapq.heappush(bidq, buy)
                if sell.quantity > 0:
                    heapq.heappush(askq, sell)
            
            printStatus(askq, bidq, shareprice)



def printStatus(askq, bidq, shareprice): 
    if shareprice >= 0:
        shareprice = str(shareprice)
    else:
            shareprice = "-"
    if len(bidq) == 0:
        bprice = "-"
    else:
        bprice=bidq[0].bprice
    if len(askq) == 0:
        sprice = "-"
    else:
        sprice = askq[0].sprice
    print(f"{sprice} {bprice} {shareprice}")
    #print(" ".join([aprice, bprice, shareprice]))




if __name__ == "__main__":
    main()


        