def main():
    m = {}
    for i in range(int(input())):
        s = input()
        if s not in m:
            m[s] = 0
        print("OK" if m[s] == 0 else s+str(m[s]))
        m[s] += 1

if __name__ == "__main__":
    main()
