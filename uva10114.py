#!/usr/bin/env python3

if __name__ == "__main__":
  while True:

    try:
        dur,down,amount,m = input().strip().split()
        m = int(m)
        dur = int (dur)
        down = float(down)
        amount = float(amount)
        value = amount + down

        coup = amount/dur
        
        depreciation = []

        for i in range(m):
            m1,r = input().strip().split()
            m1 = int(m1)
            r = float(r)
            depreciation.append((m,r))

        depr = 0

        for i in range(dur+1):
            if m > 0:
                m1,r  = depreciation[-m]
                if m1 == i:
                    depr = r
                    m -= 1
            value = value *(1-depr)
            if amount - value >= 0:
                print(i)
                break
            amount -= coup

    except EOFError:
        exit(0)







