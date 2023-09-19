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
func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}
func solve() {
	var n int
	scan(&n)
	var a []int64
	var b []int64
	var c []int64

	for i := 0; i < n; i++ {
		var x int64
		scan(&x)
		c = append(c, x)
		if x >= 0 {
			a = append(a, x)
		}
		if x <= 0 {
			b = append(b, -x)
		}
	}
	sort.Slice(a, func(i, j int) bool { return a[i] < a[j] })
	sort.Slice(b, func(i, j int) bool { return b[i] < b[j] })
	var ans int64 = c[n-1] * c[n-2]
	if len(a) >= 2 {
		ans = max(ans, a[len(a)-1]*a[len(a)-2])
	}
	if len(b) >= 2 {
		ans = max(ans, b[len(b)-1]*b[len(b)-2])
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
