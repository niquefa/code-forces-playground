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
	var a = make([]int, n+1)
	var alreadySorted bool = true
	for i := 1; i <= n; i++ {
		scan(&a[i])
		if a[i] != i {
			alreadySorted = false
		}
	}
	if alreadySorted {
		fmt.Println(0)
		return
	}
	if a[1] == 1 || a[n] == n {
		fmt.Println(1)
		return
	}
	if a[1] == n && a[n] == 1 {
		fmt.Println(3)
		return
	}
	fmt.Println(2)

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
