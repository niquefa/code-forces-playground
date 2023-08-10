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
	var n, x int
	scan(&n)
	frequency := make(map[int]int)
	for i := 0; i < n; i++ {
		scan(&x)
		frequency[x]++
	}
	var a []int
	for k, v := range frequency {
		if v%2 == 1 {
			a = append(a, k)
		}
	}
	sort.Ints(a)
	ans := 0
	for i := 1; i < len(a); i += 2 {
		ans += a[i] - a[i-1]
	}
	fmt.Println(ans)
}

func main() {
	startTime := time.Now()

	defer flush()

	solve()

	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
