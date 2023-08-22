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
	var n, q int
	scan(&n, &q)
	var a = make([]int, n+2)
	var l = make([]int, q)
	var r = make([]int, q)
	var k = make([]int, q)
	var parity = make([]int, n+2)
	var prefixSum = make([]int64, n+2)

	for i := 1; i <= n; i++ {
		scan(&a[i])
		if i == 0 {
			parity[i] = a[i] % 2
			prefixSum[i] = int64(a[i])
		} else {
			parity[i] = (parity[i-1] + a[i]) % 2
			prefixSum[i] = prefixSum[i-1] + int64(a[i])
		}
	}
	for i := 0; i < q; i++ {
		scan(&l[i], &r[i], &k[i])
	}

	var totalSum = prefixSum[n]
	for i := 0; i < q; i++ {
		var L = l[i]
		var R = r[i]
		var K = k[i]
		var toSubtract = prefixSum[R] - prefixSum[L-1]
		var leftSum = totalSum - toSubtract + int64(K*(R-L+1))
		if leftSum%2 == 1 {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
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
