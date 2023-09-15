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
func show(a []int) {
	for _, v := range a {
		printf("%d", v)
	}
	printf("\n")
}
func solve() {
	var n int
	scan(&n)

	var a int = 0
	var b int = 0
	var va []int
	var vb []int

	for i := 0; a < n || b < n; i++ {
		if i%2 == 0 {
			a += 1
			va = append(va, 1)
			b += 2
			vb = append(vb, 2)
		} else {
			a += 2
			va = append(va, 2)
			b += 1
			vb = append(vb, 1)
		}
		if b == n {
			show(vb)
			break
		}
		if a == n {
			show(va)
			break
		}
	}
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
