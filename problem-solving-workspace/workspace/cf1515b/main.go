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
func hasExactSquareRoot(n int64) bool {
	if n < 0 {
		return false
	}
	if n <= 1 {
		return true
	}

	low, high := int64(0), n
	for low <= high {
		mid := (low + high) / 2
		square := mid * mid
		if square == n {
			return true
		}
		if square < n {
			low = mid + 1
		} else {
			high = mid - 1
		}
	}
	return false
}

func solve() {
	var n int64
	scan(&n)
	if n < 10 {
		if n == 2 || n == 4 || n == 8 {
			printf("YES\n")
		} else {
			printf("NO\n")
		}
		return
	}
	if n%2 == 1 {
		printf("NO\n")
		return
	}
	if hasExactSquareRoot(n / 2) {
		printf("YES\n")
		return
	}
	if n%4 != 0 {
		printf("NO\n")
		return
	}
	if hasExactSquareRoot(n / 4) {
		printf("YES\n")
	} else {
		printf("NO\n")
	}
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
