#!/usr/bin/env python3
#
# Binary Search Tree
# https://open.kattis.com/problems/bst
#
# The balanced binary tree is necessary to get O(n log(n)) performance
# It is better to program in Java or C++ to be able to use the library functions
# instead of building a balanced binary tree from scratch
# 
# This solution passes the tests, but a much faster solution can be seen below
# https://github.com/traffaillac/traf-kattis/blob/master/bst.py
# 
# The Red Black Tree implementation below is the bare minimum to solve this problem
# It does not implement deletion

import os, sys
from enum import Enum

class Color(Enum):
    RED = 1
    BLACK = 2

class Node:
    def __init__(self, key, # key has to support < operation (i.e. __lt__ is defined)
                       color : Color=Color.RED,
                       left : 'Node'=None, # Recursive type annotation is not ('yet') allowed
                       right : 'Node'=None,
                       parent : 'Node'=None):
        self.key = key
        self.left = left
        self.right = right
        self.parent = parent
        self.color = color
    
    def __lt__(self, other):
        return self.key < other.key

class RBTree:
    """
    Red Black tree
    """
    def __init__(self):
        self.nil = Node(None, Color.BLACK)
        self.root = self.nil
    
    def insert(self, z):
        z = Node(z)
        y = self.nil
        x = self.root
        while x != self.nil:
            y = x
            if z.key < x.key:
                x = x.left
            else:
                x = x.right
        z.parent = y
        if y == self.nil:
            self.root = z
        elif z.key < y.key:
            y.left = z
        else:
            y.right = z
        
        z.left = self.nil
        z.right = self.nil
        z.color = Color.RED
        self._fixup(z)

    def findLUB(self, key):
        """
        Find the smallest element in the tree which is greater than key
        """
        return self._findLUB(self.root, key)

    def _findLUB(self, root:Node, key):
        if root == self.nil:
            return None
        elif root.key == key:
            return root.key
        elif root.key > key:
            leftlub = self._findLUB(root.left, key)
            if leftlub is None:
                return root.key
            else:
                return leftlub
        else:
            return self._findLUB(root.right, key)
    
    def findGLB(self, key):
        """
        Find the largest element in the tree which is smaller than key
        """
        return self._findGLB(self.root, key)
    
    def _findGLB(self, root:Node, key):
        if root == self.nil:
            return None
        elif root.key == key:
            return root.key
        elif root.key < key:
            leftglb = self._findGLB(root.right, key)
            if leftglb is None:
                return root.key
            else:
                return leftglb
        else:
            return self._findGLB(root.left, key)

    



    def _fixup(self, z:Node):
        while z.parent.color == Color.RED:
            if z.parent == z.parent.parent.left:
                y = z.parent.parent.right
                if y.color == Color.RED:
                    z.parent.color = Color.BLACK
                    y.color = Color.BLACK
                    z.parent.parent.color = Color.RED
                    z = z.parent.parent
                else:
                    if z == z.parent.right:
                        z = z.parent
                        self._leftRotate(z)
                    z.parent.color = Color.BLACK
                    z.parent.parent.color = Color.RED
                    self._rightRotate(z.parent.parent)
            else:
                # CHECK THIS ELSE
                y = z.parent.parent.left
                if y.color == Color.RED:
                    z.parent.color = Color.BLACK
                    y.color = Color.BLACK
                    z.parent.parent.color = Color.RED
                    z = z.parent.parent
                else:
                    if z == z.parent.left:
                        z = z.parent
                        self._rightRotate(z)
                    z.parent.color = Color.BLACK
                    z.parent.parent.color = Color.RED
                    self._leftRotate(z.parent.parent)

        self.root.color = Color.BLACK       
    
    def _leftRotate(self, x:Node):
        y = x.right
        x.right = y.left
        if y.left != self.nil:
            y.left.parent = x
        y.parent = x.parent
        if x.parent == self.nil:
            self.root = y
        elif x == x.parent.left:
            x.parent.left = y
        else:
            x.parent.right = y
        y.left = x
        x.parent = y
    
    def _rightRotate(self, y:Node):
        x = y.left
        y.left = x.right
        if x.right != self.nil:
            x.right.parent = y
        x.parent = y.parent
        if y.parent == self.nil:
            self.root = x
        elif y.parent.left == y:
            y.parent.left = x
        else:
            y.parent.right = x
        x.right = y
        y.parent = x
    
    def pprint(self):
        """
        very rudimentary pretty printer for debugging red black tree.
        This is essentially copied from https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
        """
        self._pprinthelper(self.root,"")
    
    def _pprinthelper(self, node, space):
        if node == self.nil:
            return
        newspace = space + "    "


        self._pprinthelper(node.right, newspace)
        print()
        print(end=space)
        print(node.key)

        self._pprinthelper(node.left, newspace)

    


    

def main():
    f = open(sys.argv[1]) if 'TESTR' in os.environ else sys.stdin
    n = int(f.readline())
    tree = RBTree()
    deptharray = (n+1) *[0]
    accdepth = 0
    for _ in range(n):
        i = int(f.readline())
        d = -1 
        lb = tree.findGLB(i)
        ub = tree.findLUB(i)
        if lb is not None:
            d = deptharray[lb]
        if ub is not None:
            d = max(d, deptharray[ub])
        deptharray[i] = d+1
        accdepth += deptharray[i]
        tree.insert(i)
        print(accdepth)
        






if __name__ == "__main__":
    main()