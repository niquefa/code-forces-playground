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
	var b = make([]int, n)
	for i := 0; i < n; i++ {
		scan(&b[i])
	}
	setOfDifferences := make(map[int]bool)
	possible := true
	for i := 0; i < n; i++ {
		if b[i] > a[i] {
			possible = false
		}
		if b[i] == 0 {
			continue
		}
		setOfDifferences[a[i]-b[i]] = true

	}
	if !possible || len(setOfDifferences) > 1 {
		fmt.Println("NO")
		return
	}
	if len(setOfDifferences) == 0 {
		fmt.Println("YES")
		return
	}
	var onlyDiff int
	for k := range setOfDifferences {
		onlyDiff = k
	}

	for i := 0; i < n; i++ {
		if b[i] == 0 && a[i] > onlyDiff {
			possible = false
		}
	}
	if possible {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
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
