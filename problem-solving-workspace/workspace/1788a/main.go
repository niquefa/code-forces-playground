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
	var a = make([]int, n)
	var twoCount int = 0
	for i := 0; i < n; i++ {
		scan(&a[i])
		if a[i] == 2 {
			twoCount++
		}
	}
	if twoCount == 0 {
		fmt.Println(1)
		return
	}
	if twoCount%2 == 1 {
		fmt.Println(-1)
		return
	}
	debug(n, a, twoCount)
	var otherTwoCount int = 0
	for i := 0; i < n; i++ {
		if a[i] == 2 {
			otherTwoCount++
			if otherTwoCount == twoCount/2 {
				fmt.Println(i + 1)
				return
			}
		}
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
