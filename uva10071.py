# UVA 10071 Back to High School Physics

from sys import exit



if __name__ == "__main__":

    while True:
        try:
            v,t = map(int, input().split())
            if t == 0:
                print(0)
            else:
                print(2 * v *t)
        except EOFError:
            exit(0)