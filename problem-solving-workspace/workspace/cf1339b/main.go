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
	sort.Ints(a)
	var ans = make([]int, n)
	indexLast := n - 1
	indexFirst := 0
	takeFromTail := true
	for i := 0; i < n; i++ {
		if takeFromTail {
			ans[i] = a[indexLast]
			indexLast--
		} else {
			ans[i] = a[indexFirst]
			indexFirst++
		}
		takeFromTail = !takeFromTail
	}
	//debug(a)
	//debug(ans)
	for i := 0; i < n/2; i++ {
		ans[i], ans[n-i-1] = ans[n-i-1], ans[i]
	}
	var diffs = make([]int, n-1)
	for i := 0; i < n-1; i++ {
		diffs[i] = ans[i] - ans[i+1]
		if diffs[i] < 0 {
			diffs[i] *= -1
		}
	}

	//debug(a)
	//debug(diffs)
	for i := 0; i < n; i++ {
		fmt.Print(ans[i], " ")
	}
	fmt.Println()

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
