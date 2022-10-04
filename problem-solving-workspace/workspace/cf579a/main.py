import sys


def I():
    return int(sys.stdin.readline().strip())


n = I()

print(bin(n).count("1"))
