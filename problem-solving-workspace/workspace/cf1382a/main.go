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

func solve() {
	var n, m, tmp int
	scan(&n, &m)
	var a = map[int]bool{}
	for i := 0; i < n; i++ {
		scan(&tmp)
		a[tmp] = true
	}
	var b = map[int]bool{}
	for i := 0; i < m; i++ {
		scan(&tmp)
		b[tmp] = true
	}
	debug(n, m)
	debug(a)
	debug(b)
	for k := range a {
		if b[k] {
			printf("YES\n")
			printf("1 %d\n", k)
			return
		}
	}
	printf("NO\n")
}

// ----------------------------- TEMPLATE END ----------------------------------

func main() {
	defer flush()

	var ntc int
	scan(&ntc)
	for t := 0; t < ntc; t++ {
		debug("case", t)
		solve()
	}
}
