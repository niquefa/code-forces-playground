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
	for i := 0; i < n; i++ {
		scan(&a[i])
	}
	var m int
	scan(&m)
	var b = make([]int, m)
	for i := 0; i < m; i++ {
		scan(&b[i])
	}
	var mapA = make(map[int]bool)
	for i := 0; i < n; i++ {
		mapA[a[i]] = true
	}
	var mapB = make(map[int]bool)
	for i := 0; i < m; i++ {
		mapB[b[i]] = true
	}
	for _, x := range a {
		for _, y := range b {
			if !mapA[x+y] && !mapB[x+y] {
				printf("%d %d\n", x, y)
				return
			}
		}
	}
}

func main() {
	startTime := time.Now()

	defer flush()

	var ntc int = 1
	//scan(&ntc)
	for t := 0; t < ntc; t++ {
		debug("\n====================================", t, "====================================")
		solve()
	}

	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
