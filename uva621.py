#!/usr/bin/env python3

if __name__ == "__main__":
    n = int(input())
    for _ in range(n):
        s = input().strip()
        if s == "1" or s == "4" or s == "78":
            print("+")
        elif s[-2:] == "35":
            print("-")
        elif s[0] == '9' and s[-1] == "4":
            print("*")
        else:
            print("?")
