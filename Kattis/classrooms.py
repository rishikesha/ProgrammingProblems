#!/usr/bin/env python3

# Classrooms
# https://open.kattis.com/problems/classrooms
#

import os, sys, heapq
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
    This version of Red Black Tree implements pretty much everything.
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
        Find the smallest element in the tree which is greater or equal than key
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

    def _findNode(self, root:Node, key) -> Node:
        if root == self.nil:
            return None
        elif root.key == key:
            return root
        elif root.key < key:
            return self._findNode(root.right, key)
        else:
            return self._findNode(root.left, key)

    def _rbtransplant(self, node1: Node, node2:Node):
        if node1.parent == self.nil:
            self.root = node2
        elif node1 == node1.parent.left:
            node1.parent.left = node2
        else:
            node1.parent.right = node2
        node2.parent = node1.parent
    
    def _rbdeletefixup(self, x: Node):
        while x != self.root and x.color == Color.BLACK:
            if x == x.parent.left:
                w = x.parent.right
                if w.color == Color.RED:
                    w.color = Color.BLACK
                    x.parent.color = Color.RED
                    self._leftRotate(x.parent)
                    w = x.parent.right
                if w.left.color == Color.BLACK and w.right.color == Color.BLACK:
                    w.color = Color.RED
                    x = x.parent
                else:
                    if w.right.color == Color.BLACK:
                         w.left.color = Color.BLACK
                         w.color = Color.RED
                         self._rightRotate(w)
                         w = x.parent.right

                    w.color = x.parent.color
                    x.parent.color = Color.BLACK
                    w.right.color = Color.BLACK
                    self._leftRotate(x.parent)
                    x = self.root
            else: # x == x.parent.right
                w = x.parent.left
                if w.color == Color.RED:
                    w.color = Color.BLACK
                    x.parent.color = Color.RED
                    self._rightRotate(x.parent)
                    w = x.parent.left
                if w.right.color == Color.BLACK and w.left.color == Color.BLACK:
                    w.color = Color.RED
                    x = x.parent
                else:
                    if w.left.color == Color.BLACK:
                        w.right.color = Color.BLACK
                        w.color = Color.RED
                        self._leftRotate(w)
                        w = x.parent.left
                    
                    w.color = x.parent.color
                    x.parent.color = Color.BLACK
                    w.left.color = Color.BLACK
                    self._rightRotate(x.parent)
                    x = self.root

        x.color = Color.BLACK



    def _findMinimum(self, root: Node) -> Node:
        if root == self.nil:
            return None
        else:
            while root.left != self.nil:
                root = root.left
            return root
    
    def findMinimum(self):
        if self.root != self.nil:
            return self._findMinimum(self.root).key
        else:
            return None

    def delete(self, key):
        nodeX = nodeY = nodeZ = None

        nodeZ = self._findNode(self.root, key)

        if nodeZ is None:
            raise KeyError(f"{key} not found for deletion")

        nodeY = nodeZ
        y_orig_color = nodeY.color

        if nodeZ.left == self.nil:
            nodeX = nodeZ.right
            self._rbtransplant(nodeZ, nodeZ.right)
        elif nodeZ.right == self.nil:
            nodeX = nodeZ.left
            self._rbtransplant(nodeZ, nodeZ.left)
        else:
            nodeY = self._findMinimum(nodeZ.right)
            y_orig_color = nodeY.color
            nodeX = nodeY.right
            if nodeY.parent == nodeZ:
                nodeX.parent = nodeY
            else:
                self._rbtransplant(nodeY, nodeY.right)
                nodeY.right = nodeZ.right
                nodeY.right.parent = nodeY
            self._rbtransplant(nodeZ, nodeY)
            nodeY.left = nodeZ.left
            nodeY.left.parent = nodeY
            nodeY.color = nodeZ.color
        if y_orig_color == Color.BLACK:
            self._rbdeletefixup(nodeX)


    def pprint(self):
        """
        very rudimentary pretty printer for debugging red black tree.
        This is essentially copied from https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
        """
        self._pprinthelper(self.root,"")
    
    def _pprinthelper(self, node: Node, space):
        if node == self.nil:
            return
        newspace = space + "     "

        self._pprinthelper(node.right, newspace)
        print()
        print(end=space)
        c = ""
        if node.color == Color.RED:
            c = "R"
        else:
            c = "B"

        print(str(node.key) + c)

        self._pprinthelper(node.left, newspace)

    def _checkBalanced(self, node: Node):
        if node == self.nil:
            return 1
        else:
            n1 = self._checkBalanced(node.left)
            n2 = self._checkBalanced(node.left)
            if n1 == n2:
                if node.color == Color.RED:
                    return n1
                else:
                    return n1 + 1
            else:
                raise AssertionError("The Tree is not RB")
    def checkBalanced(self):
        self._checkBalanced(self.root)


def main():
    f = open('test') if 'TESTR' in os.environ else sys.stdin
    n, k = map(int, f.readline().split())
    intervals = [tuple(map(int, f.readline().split())) for _ in range(n)]
    intervals.sort(key=lambda x : (x[1], x[0]))
    t = RBTree()
    [t.insert((-10**9, i)) for i in range(k)]
    answer = 0
    for (x,y) in intervals:
        r = t.findGLB((x-1,10**9))
        if r is not None:
            e,room = r
            t.delete(r)
            t.insert((y,room))
            answer += 1
    print(answer)

def test():
    """
    This tests the RBTree
    """
    import random
    t = RBTree()
    n = random.randint(3000, 4000)
    a = list(range(n))
    random.shuffle(a)
    for x in a:
        t.insert(x)
        t.checkBalanced()
    random.shuffle(a)
    for x in a:
        t.delete(x)
        t.checkBalanced()
    

if __name__ == "__main__":
    main()