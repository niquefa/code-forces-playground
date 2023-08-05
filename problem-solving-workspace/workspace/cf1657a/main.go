package main

import (
	"bufio"
	"fmt"
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
func isPerfectSquare(n int) bool {
	for i := 0; i*i <= n; i++ {
		if i*i == n {
			return true
		}
	}
	return false
}

func solve() {
	var x, y int
	scan(&x, &y)
	if x == 0 && y == 0 {
		fmt.Println(0)
		return
	}
	if isPerfectSquare(x*x + y*y) {
		fmt.Println(1)
		return
	}
	fmt.Println(2)
}

func main() {
	defer flush()

	var ntc int
	scan(&ntc)
	for t := 0; t < ntc; t++ {

		solve()

	}
}
