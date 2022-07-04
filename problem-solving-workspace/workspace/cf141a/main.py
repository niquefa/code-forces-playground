a = input()
b = input()
c = input()

x = sorted(list(a + b))
y = sorted(list(c))

print("YES" if x == y else "NO")
