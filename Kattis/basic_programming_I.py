if __name__ == "__main__":
    N,t = map(int, input().split())
    A = list(map(int, input().split()))
    if t == 1:
        print(7)
    elif t == 2:
        if A[0] > A[1]:
            print("Bigger")
        elif A[0] == A[1]:
            print("Equal")
        else:
            print("Smaller")
    elif t == 3:
        l = sorted([A[0], A[1], A[2]])
        print(l[1])
    elif t == 4:
        print(sum(A))
    elif t == 5:
        b = [x for x in A if x % 2 == 0]
        print(sum(b))
    elif t == 6:
        a = ord('a')
        b = [chr(x % 26 + a) for x in A]
        print("".join(b))
    elif t == 7:
        i = 0
        count = 0
        while True:
            if i >= N:
                print("Out")
                break
            elif i == N-1:
                print("Done")
                break
            elif count > N:
                print("Cyclic")
                break
            else:
                i = A[i]
            count += 1





