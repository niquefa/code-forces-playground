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
	a := make([]int, n)
	for i := 0; i < n; i++ {
		scan(&a[i])
	}
	//debug(n, a)

	sort.Sort(sort.Reverse(sort.IntSlice(a)))
	//debug(a)
	used := make([]bool, n+1)
	for _, val := range a {
		var x = val
		for x > n || used[x] {
			x /= 2
			if x == 0 {
				fmt.Println("NO")
				return
			}
		}
		used[x] = true
	}
	fmt.Println("YES")
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
