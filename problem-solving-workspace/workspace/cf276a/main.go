package main

import (
	"bufio"
	"fmt"
	"os"
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
	var n, k, f, t int
	scan(&n, &k)
	var max int = -(1 << 31)
	for i := 0; i < n; i++ {
		scan(&f, &t)
		if t > k {
			f -= t - k
		}
		if f > max {
			max = f
		}
	}
	fmt.Println(max)
}

func main() {
	startTime := time.Now()

	defer flush()

	solve()

	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
