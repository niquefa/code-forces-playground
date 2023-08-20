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
	first  int64
	second int64
}

func compare(a, b Pair) bool {
	if a.first < b.first {
		return true
	}
	if a.first == b.first {
		return a.second < b.second
	}
	return false
}

func solve() {
	var n int
	scan(&n)
	debug(n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		scan(&a[i])
	}

	v := make([]Pair, n)
	for i := 0; i < n; i++ {
		v[i] = Pair{int64(a[i]), int64(i + 1)}
	}
	sort.Slice(v, func(i, j int) bool {
		return compare(v[i], v[j])
	})
	debug(n, a, v)
	ans := int64(0)
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if v[i].first*v[j].first > int64(2)*int64(n) {
				break
			}
			if v[i].first*v[j].first == v[i].second+v[j].second {
				ans++
			}
		}
	}
	fmt.Println(ans)
}

func main() {
	startTime := time.Now()

	defer flush()

	var ntc int = 1
	scan(&ntc)
	for t := 0; t < ntc; t++ {
		debug(ntc, t)

		solve()

	}

	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
