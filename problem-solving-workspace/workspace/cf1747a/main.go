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
func abs(a int64) int64 {
	if a < 0 {
		return -a
	}
	return a
}
func max(a, b int64) int64 {
	if a < b {
		return b
	}
	return a
}
func solve() {
	var n int
	scan(&n)
	var a = make([]int64, n)
	for i := 0; i < n; i++ {
		scan(&a[i])
	}
	sort.Slice(a, func(i, j int) bool {
		return a[i] < a[j]
	})
	//debug(n)
	//debug(a)
	if n == 1 {
		fmt.Println(abs(a[0]))
		return
	}
	var sumNegatives int64 = 0
	var sumPositives int64 = 0
	var existsZero bool = false
	for i := 0; i < n; i++ {

		if a[i] < 0 {
			sumNegatives += int64(a[i])
		} else if a[i] > 0 {
			sumPositives += int64(a[i])
		} else {
			existsZero = true
		}
	}
	//debug(sumNegatives, sumPositives, existsZero)
	if existsZero && sumNegatives == 0 {
		fmt.Println(sumPositives)
		return
	}
	if existsZero && sumPositives == 0 {
		fmt.Println(abs(sumNegatives))
		return
	}
	fmt.Println(abs(abs(sumNegatives) - sumPositives))
	//	fmt.Println("?????")
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
