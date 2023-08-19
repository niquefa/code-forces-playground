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
	var s = make(map[int]bool)

	for i := 0; i < n; i++ {
		scan(&a[i])
		s[a[i]] = true
	}
	if len(s) == 1 && a[0] == 1 {
		if len(a)%2 == 1 {
			printf("First\n")
		} else {
			printf("Second\n")
		}
		return
	}
	for i := 0; i < n; i++ {
		if a[i] != 1 {
			if i%2 == 0 {
				printf("First\n")
			} else {
				printf("Second\n")
			}
			return
		}
	}

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
