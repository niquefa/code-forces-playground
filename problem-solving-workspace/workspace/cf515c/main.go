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
var sliceOfSlices = [][]int{
	{},
	{},
	{2},
	{3},
	{3, 2, 2},
	{5},
	{5, 3},
	{7},
	{7, 2, 2, 2},
	{7, 3, 3, 2},
}

func solve() {
	var n int
	var s string
	scan(&n, &s)
	debug(n, s)
	var ans []int

	for _, c := range s {
		ans = append(ans, sliceOfSlices[c-'0']...)
	}

	sort.Sort(sort.Reverse(sort.IntSlice(ans)))
	for _, c := range ans {
		printf("%d", c)
	}
	printf("\n")
}
func primeConstituents(n int) []int {
	if n < 2 {
		return []int{}
	}
	if n == 3 || n == 2 || n == 5 || n == 7 {
		return []int{n}
	}
	var f = factorial(n)
	answer := []int{}
	for i := n - 1; i >= 2; i-- {
		for {
			if f%factorial(i) != 0 {
				break
			}
			answer = append(answer, primeConstituents(i)...)
			f /= factorial(i)
		}
	}
	if f > 1 {
		debug(n, f, answer)
	}
	return answer
}
func factorial(n int) int {
	if n <= 1 {
		return 1
	}
	return n * factorial(n-1)
}

func main() {
	startTime := time.Now()
	for i := 0; i <= 9; i++ {
		debug(i, factorial(i), primeConstituents(i))
	}
	defer flush()

	var ntc int = 1
	//scan(&ntc)
	for t := 0; t < ntc; t++ {

		solve()

	}

	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
