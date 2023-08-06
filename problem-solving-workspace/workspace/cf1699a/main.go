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

func solve() {
	var n int
	scan(&n)
	//debug(n)
	if n%2 == 1 {
		fmt.Println(-1)
	} else {
		fmt.Println(0, 0, n/2)
	}

}
func findViaBruteForce(n int) (a int, b int, c int) {
	for a = 0; a <= n; a++ {
		for b = 0; a+b <= n; b++ {
			for c = 0; a+b+c <= n; c++ {
				if a^b+b^c+c^a == n {
					return
				}
			}
		}
	}
	return -1, -1, -1
}
func bruteForce(max int) {
	for n := 1; n <= max; n++ {
		a, b, c := findViaBruteForce(n)
		if a == -1 {
			debug(n, "not found")
		} else {
			sa := fmt.Sprintf("%0*b", 10, a)
			sb := fmt.Sprintf("%0*b", 10, b)
			sc := fmt.Sprintf("%0*b", 10, c)
			debug(n, "found", a, b, c)
			debug(sa)
			debug(sb)
			debug(sc)
			debug("a^b", a^b, fmt.Sprintf("%0*b", 10, a^b))
			debug("b^c", b^c, fmt.Sprintf("%0*b", 10, b^c))
			debug("c^a", c^a, fmt.Sprintf("%0*b", 10, c^a))
			assert(a^b+b^c+c^a == n)

		}
	}
}

// XOR bitwise operation
func main() {
	startTime := time.Now()
	//bruteForce(10)
	defer flush()

	var ntc int
	scan(&ntc)
	for t := 0; t < ntc; t++ {

		solve()

	}

	debug(fmt.Sprintf("%s execution time.\n", time.Since(startTime)))
}
