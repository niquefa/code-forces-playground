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
func min(a ...int) int {
	ans := a[0]
	for _, v := range a {
		if v < ans {
			ans = v
		}
	}
	return ans
}
func assert(f bool) {
	if !f {
		panic("gg Rafa, something went wrong!")
	}
}

// ----------------------------- TEMPLATE END ----------------------------------
func properDivisors(n int) []int {
	divisors := []int{}
	for i := 1; i <= n/2; i++ {
		if n%i == 0 {
			divisors = append(divisors, i)
		}
	}
	sort.Ints(divisors)
	return divisors
}

func getBiggestProperDivisor(n int) int {
	divisors := properDivisors(n)
	if len(divisors) == 0 {
		return 1
	}
	return divisors[len(divisors)-1]
}

var cache = make(map[int]int)

func f(n int) int {
	if n <= 3 {
		return n - 1
	}
	if n%2 == 0 {
		return 2
	}
	return 3
}

func solve() {
	var n int
	scan(&n)
	fmt.Println(f(n))
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
