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
func smallestMultiple(x, p int64) int64 {
	quotient := p / x
	remainder := p % x

	if remainder == 0 {
		return p
	}

	return (quotient + 1) * x
}
func min(a ...int64) int64 {
	ans := a[0]
	for _, v := range a {
		if v < ans {
			ans = v
		}
	}
	return ans
}
func solve() {
	var p, a, b, c int64
	scan(&p, &a, &b, &c)
	fmt.Println(min(smallestMultiple(a, p), smallestMultiple(b, p), smallestMultiple(c, p)) - p)

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
