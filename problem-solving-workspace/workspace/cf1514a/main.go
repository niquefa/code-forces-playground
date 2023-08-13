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
func isPerfectSquare(n int) bool {
	if n < 0 {
		return false
	}

	if n <= 1 {
		return true
	}

	low, high := 0, n/2+1
	for low <= high {
		mid := (low + high) / 2
		sq := mid * mid
		if sq == n {
			return true
		}
		if sq < n {
			low = mid + 1
		} else {
			high = mid - 1
		}
	}

	return false
}
func solve() {
	var n int
	scan(&n)
	var a = make([]int, n)
	existsNonPerfectSquare := false
	for i := 0; i < n; i++ {
		scan(&a[i])
		if !isPerfectSquare(a[i]) {
			existsNonPerfectSquare = true
		}
	}
	if existsNonPerfectSquare {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
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
