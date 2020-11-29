#!/usr/bin/env python3

#
# K Smallest Sums
# https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=296&page=show_problem&problem=3148
#

import os, sys, heapq

def main():
    f = open(sys.argv[1]) if 'TESTR' in os.environ else sys.stdin
    #f = open('test2')
    while True:
        l = f.readline()
        if len(l) == 0:
            break
        n = int(l)
        sums = n * [10**8]
        sums[0] = 0 # To ensure that the first time, the k sums will be the first array
        newsums = n *[0] # This will be used to  store merged arrays
        for _ in range(n):
            nums = list(map(int, f.readline().split()))
            nums.sort()
            pq = []
            for i in range(n):
                heapq.heappush(pq, (nums[i] + sums[0],0)) #The second of the pair is used to identify which index was used


            for i in range(n):
                newsums[i],k = heapq.heappop(pq) # This certainly belongs to the lowest n sums
                if k < n-1:
                    heapq.heappush(pq, (newsums[i] - sums[k] + sums[k+1],k+1)) # The next lowest candidate sum is pushed to heap
            sums, newsums = newsums, sums

        print(" ".join(map(str, sums)))




if __name__ == "__main__":
    main()
