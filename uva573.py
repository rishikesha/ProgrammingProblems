#/usr/bin/env python3

if __name__ == "__main__":
    while True:
        H,U,D,F = map(int, input().strip().split())
        if H == 0:
            break

        F = U*F/100.0
        height = 0
        
        i = 0

        while True:
            i += 1
            height += U
            if height > H:
                print("success on day ", i)
                break

            height -= D

            if height < 0:
                print("failure on day ", i)
                break
            U -= F
            if U <0:
                U = 0





