#!/usr/bin/env python3
#
# Binary Search Tree
# https://open.kattis.com/problems/bst
#
# The balanced binary tree is necessary to get O(n log(n)) performance
# It is better to program in Java or C++ to be able to use the library functions
# instead of building a balanced binary tree from scratch
# 
# 
# The AVL Tree implementation below is the bare minimum to solve this problem
# It does not implement deletion

import os, sys
from enum import Enum

class Node:
    def __init__(self, key, # key has to support < operation (i.e. __lt__ is defined)
                       height : int=0,
                       left : 'Node'=None, # Recursive type annotation is not ('yet') allowed
                       right : 'Node'=None,
                       parent : 'Node'=None):
        self.key = key
        self.left = left
        self.right = right
        self.parent = parent
        self.height = height
    
    def __lt__(self, other):
        return self.key < other.key

class AVLTree:
    """
    AVL tree
    """
    def __init__(self):
        self.nil = Node(None, 0)
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
        if z == self.nil:
            return
        z.height = max(z.right.height, z.left.height) + 1
        if z.right.height > z.left.height + 1:
            if z.right.right.height > z.right.left.height:
                self._leftRotate(z)
            else:
                self._rightRotate(z.right)
                self._leftRotate(z)
        elif z.left.height > z.right.height + 1:
            if z.left.left.height > z.left.right.height:
                self._rightRotate(z)
            else:
                self._leftRotate(z.left)
                self._rightRotate(z)
        z = z.parent
        self._fixup(z)


    
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
        x.height = max(x.left.height, x.right.height) + 1
        y.height = max(y.left.height, y.right.height) + 1
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
        x.height = max(x.left.height, x.right.height) + 1
        y.height = max(y.left.height, y.right.height) + 1
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
    tree = AVLTree()
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