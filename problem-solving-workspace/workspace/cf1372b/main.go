package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
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
func largestProperFactor(n int) int {
	maxFactor := 1
	limit := int(math.Sqrt(float64(n))) + 1

	for i := 2; i < limit; i++ {
		if n%i == 0 {
			factor := n / i
			if factor > maxFactor {
				maxFactor = factor
			}
		}
	}

	if maxFactor == 1 && n != 1 {
		// n is a prime number, so it only has 1 as its proper factor.
		maxFactor = 1
	}
	return maxFactor
}
func solve() {
	var n int
	scan(&n)
	var k int = largestProperFactor(n)
	fmt.Println(n-k, k)
}

func main() {
	defer flush()

	var ntc int
	scan(&ntc)
	for t := 0; t < ntc; t++ {

		solve()

	}
}
