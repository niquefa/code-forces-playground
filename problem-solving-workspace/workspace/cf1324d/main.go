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
	var n int
	scan(&n)
	var a = make([]int, n)
	for i := 0; i < n; i++ {
		scan(&a[i])
	}
	var b = make([]int, n)
	for i := 0; i < n; i++ {
		scan(&b[i])
	}
	var c = make([]int, n)
	for i := 0; i < n; i++ {
		c[i] = a[i] - b[i]
	}
	//fmt.Println("???", n, a, b, c)
	var ans int = 0
	sort.Ints(c)
	for i := 0; i < n; i++ {
		if c[i] <= 0 {
			continue
		}

		var idx int = sort.SearchInts(c, -c[i]+1)
		debug(i, c[i], idx)
		ans += i - idx
	}
	fmt.Println(ans)
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
