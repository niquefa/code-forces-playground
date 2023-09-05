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
type Pair struct {
	Value    int
	Position int
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
func solve() {
	var n, k int
	scan(&n, &k)
	var a = make([]int, n)
	for i := 0; i < n; i++ {
		scan(&a[i])
	}
	var b = make([]int, n)
	for i := 0; i < n; i++ {
		scan(&b[i])
	}
	pa := make([]Pair, n)
	for i, v := range a {
		pa[i] = Pair{Position: i, Value: v}
	}
	pb := make([]Pair, n)
	for i, v := range b {
		pb[i] = Pair{Position: i, Value: v}
	}
	sort.Slice(pa, func(i, j int) bool {
		if pa[i].Value == pa[j].Value {
			return pa[i].Position < pa[j].Position
		}
		return pa[i].Value < pa[j].Value
	})
	sort.Slice(pb, func(i, j int) bool {
		if pb[i].Value == pb[j].Value {
			return pb[i].Position < pb[j].Position
		}
		return pb[i].Value < pb[j].Value
	})
	// debug(a)
	// debug(b)
	// debug(pa)
	// debug(pb)
	var ans = make([]int, n)
	for i := 0; i < n; i++ {
		ans[pa[i].Position] = pb[i].Value
	}
	for i := 0; i < n; i++ {
		fmt.Print(ans[i], " ")
	}
	fmt.Println()
}

func main() {
	startTime := time.Now()

	defer flush()

	var ntc int = 1
	scan(&ntc)
	for t := 0; t < ntc; t++ {
		//debug("\n====================================", t, "====================================")
		solve()
	}

	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
