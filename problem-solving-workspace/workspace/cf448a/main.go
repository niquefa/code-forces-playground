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
	var a, b, c, d, e, f, n int
	scan(&a, &b, &c, &d, &e, &f, &n)
	debug(a, b, c, d, e, f, n)
	var cups = a + b + c
	var medals = d + e + f
	var usedShelves = cups / 5

	if cups%5 != 0 {
		usedShelves++
	}
	usedShelves += medals / 10
	if medals%10 != 0 {
		usedShelves++
	}
	debug(n, cups, medals, usedShelves)
	if usedShelves <= n {
		printf("YES\n")
	} else {
		printf("NO\n")
	}

}

// ----------------------------- TEMPLATE END ----------------------------------

func main() {
	defer flush()
	solve()
}
