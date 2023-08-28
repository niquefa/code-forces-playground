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
func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}
func abs(a int64) int64 {
	if a < 0 {
		return -a
	}
	return a
}
func solve() {
	var n int
	scan(&n)
	var s int64 = 0
	var a = make([]int64, n)
	for i := 0; i < n; i++ {
		scan(&a[i])
		s += a[i]
	}
	var ans int64 = s - 2*a[0] - 2*a[1]
	for i := 1; i < n; i++ {
		ans = max(ans, s-2*a[i]-2*a[i-1])
	}
	fmt.Println(ans)
}

func main() {
	startTime := time.Now()

	defer flush()

	var ntc int = 1
	scan(&ntc)
	for t := 0; t < ntc; t++ {
		debug("\n====================================", t, "====================================")
		solve()
	}

	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
