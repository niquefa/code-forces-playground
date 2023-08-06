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

func solve() {
	var n int = 5
	var a int
	var sum int = 0
	for i := 0; i < n; i++ {
		scan(&a)
		sum += a
	}
	debug(n, sum)
	if sum != 0 && sum%n == 0 {
		fmt.Println(sum / n)
	} else {
		fmt.Println(-1)
	}
}

func main() {
	defer flush()
	solve()
}
