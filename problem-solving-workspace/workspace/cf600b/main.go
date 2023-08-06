package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strings"
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
	var n, m int
	scan(&n, &m)
	var a = make([]int, n)
	for i := 0; i < n; i++ {
		scan(&a[i])
	}
	var b = make([]int, m)
	for i := 0; i < m; i++ {
		scan(&b[i])
	}
	//fmt.Println(a, b)
	sort.Ints(a)
	var sb strings.Builder
	for _, x := range b {
		ans := sort.Search(len(a), func(i int) bool { return a[i] > x })
		sb.WriteString(fmt.Sprintf("%d ", ans))
	}
	fmt.Println(sb.String())
}

func main() {
	startTime := time.Now()

	defer flush()
	solve()

	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
