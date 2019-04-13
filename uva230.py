#!/usr/bin/env python3
class Book:
    def __init__(self, book):
        self._parsebook(book)

    def _parsebook(self, book):
        n = book.find("\"", 1)
        self._title = book[0:n+1]
        self._author = book[n+5:]
        self._inlibrary = True
        self._onshelf = True

    @property
    def title(self):
        return self._title

    @property
    def author(self):
        return self._author

    def borrowbook(self):
        self._inlibrary = False
        self._onshelf = False

    def returnbook(self):
        self._inlibrary = True
        self._onshelf = False

    def shelvebook(self):
        self._inlibrary = True
        self._onshelf = True

    @property
    def onshelf(self):
        return self._onshelf

    @property
    def inlibrary(self):
        return self._inlibrary

    def __lt__(self, other):
        f = (self.author , self.title)
        r = (other.author , other.title)
        return f < r

    def __eq__(self, other):
        f = (self.author , self.title)
        r = (other.author , other.title)
        return f == r




class Catalog:
    def __init__(self):
        self._books = []
    
    def addBook(self, book):
        b = Book(book)
        import bisect
        bisect.insort(self._books, b)

    def getindex(self, title):
        for i,b in enumerate(self._books):
            if b.title == title:
                return i
        return -1


    def processRequest(self,inp):
        req = inp[:6]
        title = inp[7:]

        if req == "BORROW":
            i = self.getindex(title)
            self._books[i].borrowbook()

        elif req == "RETURN":
            i = self.getindex(title)
            self._books[i].returnbook()

        elif req == "SHELVE":
            for i,b in enumerate(self._books):
                if b.inlibrary and not b.onshelf:
                    j = i - 1
                    while j >= 0:
                        if not self._books[j].onshelf:
                            j -= 1
                        else:
                            print("Put %s after %s"%
                                    (b.title, self._books[j].title))
                            break

                    if j < 0:
                        print("Put %s first"%b.title)
                    b.shelvebook()
            print("END")




if __name__ == "__main__":
    catalog = Catalog()

    while True:
        book = input().strip()
        if book == "END":
            break
        catalog.addBook(book)


    while True:
        inp = input().strip()
        if inp == "END":
            break

        catalog.processRequest(inp)


