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
const oo = 99999999

func solve() {
	var n int
	scan(&n)
	var m = make([]int, n)
	var tmp string
	var best01 int = oo
	var best10 int = oo
	var best11 int = oo
	for i := 0; i < n; i++ {
		scan(&m[i], &tmp)
		if tmp == "01" && m[i] < best01 {
			best01 = m[i]
		}
		if tmp == "10" && m[i] < best10 {
			best10 = m[i]
		}
		if tmp == "11" && m[i] < best11 {
			best11 = m[i]
		}

	}
	if best01 == oo && best10 == oo && best11 == oo {
		printf("-1\n")
		return
	}
	candidates := []int{best01 + best10, best11}
	sort.Ints(candidates)
	if candidates[0] >= oo {
		printf("-1\n")
		return
	}
	printf("%d\n", candidates[0])
}

func main() {
	startTime := time.Now()

	defer flush()

	var ntc int = 1
	scan(&ntc)
	for t := 0; t < ntc; t++ {

		solve()

	}

	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
