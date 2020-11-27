#!/usr/bin/env python3

# Teque
# https://open.kattis.com/problems/teque
#
# There are two classes Teque and Teque2. I made the second class to get over the TLE error (Time limit exceeded)
# I am leaving both the classes for informational purpose
#

import os, sys
from collections import deque

class Teque:
    class Node:
        def __init__(self,x,prv=None, nxt=None):
            self.val = x
            self.prv = prv
            self.nxt = nxt
    
    def __init__(self):
        self._head = self.Node(-1)
        self._tail = self.Node(-1, self._head, None)
        self._head.nxt = self._tail
        self._middle = self._head
        self._length = 0


    def push_back(self,x):
        n = self.Node(x,self._tail.prv, self._tail)
        n.prv.nxt = n
        self._tail.prv = n

        self._length += 1
        if self._length == 1:
            self._middle = n
        elif self._length % 2 == 1:
            self._middle = self._middle.nxt

    def push_front(self,x):
        n = self.Node(x, self._head, self._head.nxt)
        n.nxt.prv = n
        self._head.nxt = n
        self._length += 1
        if self._length == 1:
            self._middle = n
        elif self._length % 2 == 0:
            self._middle = self._middle.prv

    def push_middle(self,x):
        n = self.Node(x,self._middle, self._middle.nxt)
        n.nxt.prv = n
        n.prv.nxt = n

        self._length += 1
        if self._length % 2 == 1:
            self._middle = n


    def get(self, i):
        n = self._head.nxt
        for _ in range(i):
            n = n.nxt
        return n.val



class Teque2:

    def __init__(self):
        self.d1  = deque()
        self.d2  = deque()
    
    def  push_back(self, x):
        self.d2.append(x)
        while len(self.d2) > len(self.d1):
            u = self.d2.popleft()
            self.d1.append(u)
        
    def push_front(self,x):
        self.d1.appendleft(x)
        if len(self.d1) > len(self.d2) +1:
            u = self.d1.pop()
            self.d2.appendleft(u)
    
    def push_middle(self,x):
        if len(self.d1) == len(self.d2):
            self.d1.append(x)
        else:
            self.d2.appendleft(x)
    
    def get(self, i):
        if i < len(self.d1):
            return self.d1[i]
        else:
            return self.d2[i - len(self.d1)]





if __name__ == "__main__":
    teque = Teque2()
    f = open(sys.argv[1]) if 'TESTR' in os.environ else sys.stdin
    #f = open('test')
    n = int(f.readline())
    for _ in range(n):
        command = f.readline().strip().split()
        if command[0] == "push_back":
            teque.push_back(command[1])
        elif command[0] == "push_front":
            teque.push_front(command[1])
        elif command[0] == "push_middle":
            teque.push_middle(command[1])
        elif command[0] == "get":
            print(teque.get(int(command[1])))

