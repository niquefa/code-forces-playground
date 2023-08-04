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
		panic("gg Rafa, something went wrong!")
	}
}

// ----------------------------- TEMPLATE END ----------------------------------

func solve() {
	var n, x int
	scan(&n, &x)
	var a = make([]float64, n)
	for i := 0; i < n; i++ {
		scan(&a[i])
	}
	sort.Sort(sort.Reverse(sort.Float64Slice(a)))

	var prefixXum = make([]float64, n)
	prefixXum[0] = a[0]
	for i := 1; i < n; i++ {
		prefixXum[i] = prefixXum[i-1] + a[i]
	}
	ans := 0
	for i := 0; i < n; i++ {
		if prefixXum[i]/float64(i+1) >= float64(x) {
			ans = i + 1
		}
	}
	fmt.Println(ans)
	//fmt.Println(n, x, a, prefixXum)

}

func main() {
	defer flush()

	var ntc int
	scan(&ntc)
	for t := 0; t < ntc; t++ {

		solve()

	}
}
