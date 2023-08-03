package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
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
	var n, q, x, y int
	scan(&n, &q)
	var a = make([]int64, n)
	for i := 0; i < n; i++ {
		scan(&a[i])
	}
	sort.Slice(a, func(i, j int) bool { return a[i] > a[j] })

	var prefixSum = make([]int64, n+1)
	for i := 0; i < n; i++ {
		prefixSum[i+1] = prefixSum[i] + a[i]
	}
	//debug(a)
	//debug(prefixSum)
	for i := 0; i < q; i++ {
		scan(&x, &y)
		fmt.Println(prefixSum[x] - prefixSum[x-y])
	}
}

// ----------------------------- TEMPLATE END ----------------------------------

func main() {
	defer flush()

	solve()
}
