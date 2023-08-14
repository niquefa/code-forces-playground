package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"time"
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
		panic("gg Rafa, something went wrong!")
	}
}

// ----------------------------- TEMPLATE END ----------------------------------

func solve() {
	var n, x int
	scan(&n, &x)
	var a = make([]int, 2*n)
	for i := 0; i < 2*n; i++ {
		scan(&a[i])
	}
	sort.Ints(a)
	var b = make([]int, n)
	var c = make([]int, n)
	for i := 0; i < n; i++ {
		b[i] = a[i]
		c[i] = a[n+i]
	}
	var can = true
	for i := 0; i < n; i++ {
		if c[i] < b[i]+x {
			can = false
			break
		}
	}
	//debug(n, x)
	//debug(a, b, c)
	if can {
		printf("YES\n")
	} else {
		printf("NO\n")
	}
}

func main() {
	startTime := time.Now()

	defer flush()

	var ntc int
	scan(&ntc)
	for t := 0; t < ntc; t++ {

		solve()

	}

	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
