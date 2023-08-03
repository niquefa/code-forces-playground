package main

import (
	"bufio"
	"fmt"
	"math"
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
		panic("gg")
	}
}

func getDivisors(n int64) []int64 {
	var divisors []int64

	divisors = append(divisors, 1)
	if n != 1 {
		divisors = append(divisors, n)
	}

	for i := int64(2); i <= int64(math.Sqrt(float64(n))); i++ {
		if n%i == 0 {
			divisors = append(divisors, i)
			if n/i != i {
				divisors = append(divisors, n/i)
			}
		}
	}

	sort.Slice(divisors, func(i, j int) bool { return divisors[i] < divisors[j] })

	return divisors
}

func getMinDiff(a []int64) int64 {
	var minDiff int64 = math.MaxInt64
	for i := 1; i < len(a); i++ {
		if a[i]-a[i-1] < minDiff {
			minDiff = a[i] - a[i-1]
		}
	}
	return minDiff
}

func solve() {
	var n int
	scan(&n)
	fmt.Println(answer[n])
	if answer[n] != 0 {
		fmt.Println(answer[n])
		return
	}
	for {
		n++
		if _, alreadyInMap := answer[int(n)]; alreadyInMap {
			fmt.Println(answer[n])
			return
		}
	}
}

// ----------------------------- TEMPLATE END ----------------------------------
var answer = make(map[int]int)

func main() {
	start := time.Now()
	defer flush()
	answer[1] = 6
	answer[2] = 15
	for n := 3; n <= 1000000; n++ {
		divisors := getDivisors(int64(n))
		if len(divisors) < 4 {
			continue
		}
		d := getMinDiff(divisors)
		if _, alreadyInMap := answer[int(d)]; !alreadyInMap {
			answer[int(d)] = n
			debug(n, d, divisors)
		}
	}
	var ntc int
	scan(&ntc)
	for t := 0; t < ntc; t++ {
		solve()
	}
	elapsed := time.Since(start)
	debug("Running Time: ", elapsed)
}
