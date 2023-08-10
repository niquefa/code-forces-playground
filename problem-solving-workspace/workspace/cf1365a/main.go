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
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func solve() {
	var n, m int
	scan(&n, &m)
	var g = make([][]int, n)
	allZeroColumnCount := 0
	allZeroRowCount := 0
	for i := 0; i < n; i++ {
		var a = make([]int, m)
		allZero := true
		for j := 0; j < m; j++ {
			scan(&a[j])
			if a[j] != 0 {
				allZero = false
			}
		}
		if allZero {
			allZeroRowCount++
		}
		g[i] = a
	}
	for j := 0; j < m; j++ {
		allZero := true
		for i := 0; i < n; i++ {
			if g[i][j] != 0 {
				allZero = false
			}
		}
		if allZero {
			allZeroColumnCount++
		}
	}
	//debug(n, m, g)
	//debug(allZeroColumnCount, allZeroRowCount)
	if min(allZeroColumnCount, allZeroRowCount)%2 == 1 {
		fmt.Println("Ashish")
	} else {
		fmt.Println("Vivek")
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
