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
	var n int
	scan(&n)
	var b = make([]int, n)
	for i := 0; i < n; i++ {
		scan(&b[i])
	}
	debug(n, b)
	var maxSoFar = b[0]
	for i := 0; i < n; i++ {
		if i == 0 {
			fmt.Print(b[0], " ")
			continue
		}
		var iValue = b[i] + max(0, maxSoFar)
		fmt.Print(iValue, " ")
		if iValue > maxSoFar {
			maxSoFar = iValue
		}
	}
	fmt.Println()

}

func main() {
	startTime := time.Now()

	defer flush()

	var ntc int = 1
	//scan(&ntc)
	for t := 0; t < ntc; t++ {
		debug("\n====================================", t, "====================================")
		solve()
	}

	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
