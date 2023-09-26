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
func sumFromOneToN(n int64) int64 {
	return (n * (n + 1)) / 2
}
func solve() {
	var n, k, x int64
	scan(&n, &k, &x)
	maxSumWithKDistinct := sumFromOneToN(n) - sumFromOneToN(n-k)
	minSumWithKDistinct := sumFromOneToN(k)
	debug(n, k, x, maxSumWithKDistinct, minSumWithKDistinct)

	if minSumWithKDistinct > x {
		fmt.Println("NO")
		return
	}
	if x > maxSumWithKDistinct {
		fmt.Println("NO")
		return
	}
	if x == maxSumWithKDistinct {
		fmt.Println("YES")
		return
	}
	fmt.Println("YES")

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
