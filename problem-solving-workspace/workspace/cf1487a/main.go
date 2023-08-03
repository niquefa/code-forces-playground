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
	var a = make([]int, n)
	var lowestValue int = 101
	for i := 0; i < n; i++ {
		scan(&a[i])
		if a[i] < lowestValue {
			lowestValue = a[i]
		}
	}
	var ans int = 0
	for i := 0; i < n; i++ {
		if a[i] > lowestValue {
			ans++
		}
	}
	printf("%v\n", ans)

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
