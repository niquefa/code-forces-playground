package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
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
	for i := 0; i < n; i++ {
		scan(&a[i])
	}
	sort.Ints(a)
	var ans int = 0

	for i := 0; i < n; i++ {
		if a[i] <= i+1 {
			ans = i + 1
		} else {
			for j := i + 1; j < n; j++ {
				if a[j] <= j+1 {
					ans = j + 1
				}
			}
			break
		}
	}
	debug(n, a)
	fmt.Println(ans + 1)
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
