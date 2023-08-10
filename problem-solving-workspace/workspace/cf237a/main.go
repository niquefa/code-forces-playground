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
	var h = make([]int, n)
	var m = make([]int, n)
	cnt := 1
	answer := 1
	for i := 0; i < n; i++ {
		scan(&h[i], &m[i])
		if i == 0 {
			continue
		}
		if h[i] == h[i-1] && m[i] == m[i-1] {
			cnt++
			if cnt > answer {
				answer = cnt
			}
		} else {
			cnt = 1
		}
	}
	fmt.Println(answer)

}

func main() {
	startTime := time.Now()

	defer flush()
	solve()

	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
