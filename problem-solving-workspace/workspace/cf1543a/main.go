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
func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}
func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

// ----------------------------- TEMPLATE END ----------------------------------

func solve() {
	var a, b int64
	scan(&a, &b)

	if a == b {
		fmt.Println(0, 0)
		return
	}
	d := max(a, b) - min(a, b)
	fmt.Println(d, min(a%d, d-a%d))
}

func main() {
	defer flush()

	var ntc int
	scan(&ntc)
	for t := 0; t < ntc; t++ {

		solve()

	}
}
