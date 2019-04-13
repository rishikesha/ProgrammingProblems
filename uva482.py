


if __name__ == "__main__":

    n = int(input())

    for _ in range(n):
        input()
        p = list(map(int, input().split()))
        a = list(input().split())
        b = [0] * len(p)
        for i, x in enumerate(p):
            b[x-1] = a[i]
        for x in b:
            print(x)

        print("")
