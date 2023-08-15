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
	var n, s, r int
	scan(&n, &s, &r)
	var a = make([]int, n)
	a[0] = s - r
	for i := 1; i < n; i++ {
		a[i] = 1
	}
	//debug(a)
	for {
		sum := 0
		for i := 0; i < n; i++ {
			sum += a[i]
		}
		//debug(a, sum, s)
		if sum == s {
			break
		}

		for i := 1; i < n; i++ {
			if a[i] < a[0] {
				a[i]++
				break
			}
		}
	}
	//debug(a)
	for i := 0; i < n; i++ {
		printf("%d ", a[i])
	}
	printf("\n")
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
