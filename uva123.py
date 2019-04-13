#!/usr/bin/env python3



if __name__ == "__main__":

    ignored = set([])

    indexed = []

    while True:
        w = input().strip()
        if w == "::":
            break
        ignored.add(w.lower())


    j=0
    while True:
        j += 1
        try:
            title = input().strip().lower()
        except EOFError:
            break

        title = title.split()
        for i,w in enumerate(title):
            if w not in ignored:
                w=w.upper()
                s = title[:i] + [w] + title[i+1:]
                indexed.append((w,j," ".join(s)))

    indexed=sorted(indexed)
    for _,_,s in indexed:
        print(s,end='\n')





