package main

import (
	"bufio"
	"fmt"
	"os"
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
	var n int
	scan(&n)
	var a = make([]int, n)
	for i := 0; i < n; i++ {
		scan(&a[i])
	}
	var minDiff int = 1000000000
	var minDiffIndex1 int = -1
	var minDiffIndex2 int = -1

	for i := 0; i < n; i++ {
		var j int = (i + 1) % n
		var diff int = a[i] - a[j]
		if diff < 0 {
			diff = -diff
		}
		if diff < minDiff {
			minDiff = diff
			minDiffIndex1 = i
			minDiffIndex2 = j
		}

	}
	debug(minDiff, minDiffIndex1, minDiffIndex2)
	fmt.Println(minDiffIndex1+1, minDiffIndex2+1)
}

// ----------------------------- TEMPLATE END ----------------------------------

func main() {
	defer flush()
	solve()
}
