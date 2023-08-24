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
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func solve() {
	var n, k int
	scan(&n, &k)
	var a = make([]int, n+2)
	a[0] = k
	a[n+1] = k
	for i := 1; i <= n; i++ {
		scan(&a[i])
	}
	var e int = 0
	var b = make([]int, n+2)
	for i := 1; i <= n; i++ {
		if a[i]+a[i-1] < k {
			e += k - (a[i] + a[i-1])
			a[i] += k - (a[i] + a[i-1])
		}
		b[i] = a[i]
	}
	fmt.Println(e)
	for i := 1; i <= n; i++ {
		fmt.Print(b[i], " ")
	}
	fmt.Println()
}

func main() {
	startTime := time.Now()

	defer flush()

	var ntc int = 1
	for t := 0; t < ntc; t++ {
		debug("\n====================================", t, "====================================")
		solve()
	}

	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
