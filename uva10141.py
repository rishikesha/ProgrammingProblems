#!/usr/bin/env python3



if __name__ == "__main__":
    i = 0
    while True:
        i += 1
        proposals = []
        try: 
            inp = input()

            n,p = map(int, inp.split())
            if n == 0:
                break

            for _ in range(n):
                input()

            for _ in range(p):
                vendor = input()
                price, reqs = input().split()
                price = float(price)
                reqs = int(reqs)
                proposals.append((reqs, price, vendor))
                for _ in range(reqs):
                    input()

            proposals.sort(key=lambda e: (-e[0], e[1]))

            print("RFP #%d"%i)
            print(proposals[0][2])











        except EOFError:
            break
