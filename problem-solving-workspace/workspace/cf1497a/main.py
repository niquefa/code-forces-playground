import sys
from collections import Counter


def I():
    return int(sys.stdin.readline().strip())


def LI():
    return list(map(int, sys.stdin.readline().strip().split()))


def solve():
    n = I()
    a = LI()
    m = Counter(a)
    prefix_list = []
    key_set = set(m.keys())
    for key in key_set:
        prefix_list.append(key)
        if m[key] > 1:
            m[key] = m[key] - 1
        else:
            if m[key] == 1:
                m.pop(key)

    prefix_list.sort()

    for key, value in m.items():
        prefix_list += [key] * value

    for i in range(len(prefix_list)):
        print(prefix_list[i], end=" " if i < len(prefix_list) - 1 else "\n")


def main():
    test_count = I()
    for _ in range(test_count):
        solve()


if __name__ == "__main__":
    main()
