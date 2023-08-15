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

func factorial(n int64) int64 {
	if n == 0 {
		return 1
	}
	var result int64 = 1
	var i int64
	for i = 2; i <= n; i++ {
		result *= i
	}
	return result
}

func C(n, k int64) int64 {
	return factorial(n) / (factorial(k) * factorial(n-k))
}

func valid(s string) bool {
	m := make(map[rune]int)
	for _, ch := range s {
		m[ch]++
	}
	if len(m) != 2 {
		return false
	}
	for _, v := range m {
		if v != 2 {
			return false
		}
	}
	return true
}
func solve() {
	var n int64
	scan(&n)
	var a = make([]int64, n)
	var i int64
	for i = 0; i < n; i++ {
		scan(&a[i])
	}
	//By formula also work
	// var result int64 = C(4, 2) * C(10-n, 2)
	// debug(C(4, 2), C(10-n, 2), result)
	// fmt.Println(result)
	var D string = "abcdefghij"[:10-n]
	debug(n, a, D)
	var allDifferentSets = make(map[string]bool)
	for _, a := range D {
		for _, b := range D {
			for _, c := range D {
				for _, d := range D {
					var s string = string([]rune{a, b, c, d})
					if valid(s) {
						allDifferentSets[s] = true
					}
				}
			}
		}
	}
	fmt.Println(len(allDifferentSets))
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
