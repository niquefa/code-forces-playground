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
	var m = make(map[int]int)
	for i := 0; i < n; i++ {
		scan(&a[i])
		m[a[i]]++
	}
	sort.Sort(sort.Reverse(sort.IntSlice(a)))
	//debug(a, m)
	for _, k := range a {
		if m[k+1] == 0 && m[k] > 1 {
			m[k+1]++
			m[k]--
		} else if m[k] == 1 && m[k+1] == 0 {
			m[k]--
			delete(m, k)
			m[k+1]++
		}
	}
	fmt.Println(len(m))
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
