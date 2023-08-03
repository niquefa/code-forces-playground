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
	var coins = make([]int, 101)
	var n, coin int
	scan(&n)
	var pockets = 0
	for i := 0; i < n; i++ {
		scan(&coin)
		coins[coin]++
		if coins[coin] > pockets {
			pockets = coins[coin]
		}
	}
	fmt.Println(pockets)
}

// ----------------------------- TEMPLATE END ----------------------------------

func main() {
	defer flush()
	solve()
}
