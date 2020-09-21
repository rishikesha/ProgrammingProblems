
if __name__ == "__main__":
    while True:
        try:
            s = input()
        except EOFError:
            break
        if s is None:
            break
        m,n = map(int,s.split())
        print(abs(m-n))
