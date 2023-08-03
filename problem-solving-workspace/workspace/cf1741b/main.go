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
		panic("gg")
	}
}

func solve() {
	var n int
	scan(&n)
	if n == 1 || n == 3 {
		fmt.Println(-1)
		return
	}
	if n%2 == 0 {
		for i := 1; i <= n; i += 2 {
			fmt.Printf("%d %d ", i+1, i)
		}
		fmt.Println()
		return
	}
	for i := 4; i <= n; i += 2 {
		fmt.Printf("%d %d ", i, i+1)
	}
	fmt.Println("1 2 3")
}

// ----------------------------- TEMPLATE END ----------------------------------

func main() {
	defer flush()

	var ntc int
	scan(&ntc)
	for t := 0; t < ntc; t++ {
		solve()
	}
}
