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
var allPositiveSolutions = make(map[int]bool)
var primes = []int{2, 3, 5, 7}
var nearlyPrimes = make(map[int]bool)
var nearlyPrimesAsSlice []int
var solutions = make(map[int][]int)

func ok(n int) bool {
	var d int
	for _, a := range nearlyPrimesAsSlice {
		for _, b := range nearlyPrimesAsSlice {
			if a == b {
				continue
			}
			for _, c := range nearlyPrimesAsSlice {
				if a == c || b == c {
					continue
				}
				d = n - a - b - c
				if d > 0 && d != a && d != b && d != c {
					solutions[n] = []int{a, b, c, d}
					return true
				}
			}
		}
	}
	return false
}

func precompute() {

	for i := 0; i < len(primes); i++ {
		for j := 0; j < len(primes); j++ {
			if i == j {
				continue
			}
			nearlyPrimes[primes[i]*primes[j]] = true
		}
	}
	for k := range nearlyPrimes {
		nearlyPrimesAsSlice = append(nearlyPrimesAsSlice, k)
	}
	sort.Ints(nearlyPrimesAsSlice)
	debug(nearlyPrimesAsSlice)
	for n := 1; n <= 200000; n++ {
		allPositiveSolutions[n] = ok(n)
	}
}

func solve() {
	var n int
	scan(&n)
	if allPositiveSolutions[n] {
		printf("YES\n")
		for i := 0; i < 4; i++ {
			printf("%d ", solutions[n][i])
		}
		printf("\n")
	} else {
		printf("NO\n")
	}
}

func main() {
	startTime := time.Now()
	precompute()
	defer flush()

	var ntc int
	scan(&ntc)
	for t := 0; t < ntc; t++ {

		solve()

	}

	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
