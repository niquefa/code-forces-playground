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
	var n, m int
	scan(&n)
	var a = make([]int, n+1)
	var l = make([]int, n+1)
	var r = make([]int, n+1)
	for i := 0; i < n; i++ {
		scan(&a[i])
		l[a[i]] = i + 1
		r[a[i]] = n - i
	}
	scan(&m)
	var tmp int
	var ans1 int64 = 0
	var ans2 int64 = 0
	debug(n, m, a)
	for i := 0; i < m; i++ {
		scan(&tmp)
		ans1 += int64(l[tmp])
		ans2 += int64(r[tmp])
	}
	printf("%d %d\n", ans1, ans2)
}

func main() {
	startTime := time.Now()

	defer flush()

	var ntc int = 1
	//scan(&ntc)
	for t := 0; t < ntc; t++ {

		solve()

	}

	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
