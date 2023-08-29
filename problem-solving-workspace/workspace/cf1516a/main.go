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
	var n, k int
	scan(&n, &k)
	var a = make([]int, n)
	for i := 0; i < n; i++ {
		scan(&a[i])
	}
	var operations int = 0
	var i int = 0
	//debug(n, k, a, operations, i)
	for {
		if operations == k || i == n {
			break
		}
		if a[i] == 0 {
			i++
			continue
		}
		var change = false
		for j := n - 1; j > i; j-- {

			if a[i] > 0 && a[j] >= 0 {
				a[i]--
				a[j]++
				operations++
				change = true
				break
			}
		}
		//debug(a, operations, i, change)
		if !change {
			break
		}
	}

	debug(a)
	for i := 0; i < n; i++ {
		printf("%d ", a[i])
	}
	printf("\n")
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
