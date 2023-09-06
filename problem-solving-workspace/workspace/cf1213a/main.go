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
	var even, odd int = 0, 0
	for i := 0; i < n; i++ {
		var x int
		scan(&x)
		if x%2 == 0 {
			even++
		} else {
			odd++
		}
	}
	if even > odd {
		printf("%d\n", odd)
	} else {
		printf("%d\n", even)
	}
}

func main() {
	startTime := time.Now()

	defer flush()
	solve()
	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
