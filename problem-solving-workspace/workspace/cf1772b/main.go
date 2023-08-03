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
func debug(a ...interface{})            { fmt.Fprintln(os.Stderr, a...) }
func assert(f bool) {
	if !f {
		panic("gg")
	}
}
func isBeautiful(m [][]int) bool {
	if m[0][0] >= m[0][1] || m[1][0] >= m[1][1] {
		return false
	}
	if m[0][0] >= m[1][0] || m[0][1] >= m[1][1] {
		return false
	}
	return true
}
func solve() {
	m := [][]int{
		{0, 0},
		{0, 0},
	}
	scan(&m[0][0], &m[0][1], &m[1][0], &m[1][1])
	debug(m[0])
	debug(m[1])
	for i := 0; i < 4; i++ {
		if isBeautiful(m) {
			printf("YES\n")
			return
		}
		m[0][0], m[0][1], m[1][0], m[1][1] = m[1][0], m[0][0], m[1][1], m[0][1]
		debug("after rotation ", i)
		debug(m[0])
		debug(m[1])
	}
	printf("NO\n")
}

// ----------------------------- TEMPLATE END ----------------------------------

func main() {
	defer flush()

	var ntc int
	scan(&ntc)
	for t := 0; t < ntc; t++ {
		solve()
	}
}
