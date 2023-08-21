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
	debug(n, a, b)
	var t1 []int
	var t0 []int
	var groupOf = make(map[int]int)
	for i := 0; i < n; i++ {
		if b[i] == 1 {
			t1 = append(t1, a[i])
		} else {
			t0 = append(t0, a[i])
		}
		groupOf[a[i]] = b[i]
	}
	debug("t1", t1, "t0", t0)
	if len(t0) == 0 {
		if sort.IntsAreSorted(t1) {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
		return
	}
	if len(t1) == 0 {
		if sort.IntsAreSorted(t0) {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
		return
	}
	fmt.Println("Yes")
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
