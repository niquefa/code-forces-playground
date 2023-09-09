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
	var n, k int
	scan(&n, &k)
	var a = make([]int, n)
	var set = make(map[int]bool)
	for i := 0; i < n; i++ {
		scan(&a[i])
		set[a[i]] = true
	}
	if len(set) < k {
		printf("NO\n")
		return
	}
	printf("YES\n")
	for i := 0; i < n; i++ {
		if k == 0 {
			break
		}
		if set[a[i]] {
			printf("%d ", i+1)
			set[a[i]] = false
			k--
		}
	}

}

func main() {
	startTime := time.Now()

	defer flush()
	solve()

	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
