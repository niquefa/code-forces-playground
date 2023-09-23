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
	var n, m int
	scan(&n, &m)

	var isA = make([]bool, m+1)
	for i := 0; i < n; i++ {
		var ai int
		scan(&ai)
		var indexes []int
		indexes = append(indexes, ai)
		indexes = append(indexes, m-ai+1)
		sort.Ints(indexes)

		if !isA[indexes[0]] {
			isA[indexes[0]] = true
		} else {
			isA[indexes[1]] = true
		}
	}
	for i := 1; i <= m; i++ {
		if isA[i] {
			fmt.Print("A")
		} else {
			fmt.Print("B")
		}
	}
	fmt.Println()
}

func main() {
	startTime := time.Now()

	defer flush()

	var ntc int = 1
	scan(&ntc)
	for t := 0; t < ntc; t++ {
		debug("\n====================================", t, "====================================")
		solve()
	}

	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
