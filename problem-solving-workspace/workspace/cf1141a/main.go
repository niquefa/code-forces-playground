package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func flush()                            { out.Flush() }
func scan(a ...interface{})             { fmt.Fscan(in, a...) }
func printf(f string, a ...interface{}) { fmt.Fprintf(out, f, a...) }
func assert(f bool) {
	if !f {
		panic("gg")
	}
}

const INF = 1e9

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func f(n, m int) int {
	if n == m {
		return 0
	}
	var option2 = -1
	if m%2 == 0 {
		option2 = 1 + f(n, m/2)
	}
	var option3 = -1
	if m%3 == 0 {
		option3 = 1 + f(n, m/3)
	}
	if option2 == -1 && option3 == -1 {
		return INF
	}
	if option2 == -1 {
		return option3
	}
	if option3 == -1 {
		return option2
	}
	return min(option2, option3)
}

func solve() {
	var n, m int
	scan(&n, &m)
	if n == m {
		fmt.Println(0)
		return
	}
	var answer = f(n, m)
	if answer >= INF {
		fmt.Println(-1)
	} else {
		fmt.Println(answer)
	}
}

// ----------------------------- TEMPLATE END ----------------------------------

func main() {
	defer flush()
	solve()
}
