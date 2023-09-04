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
var f []int

func solve() {
	var n int
	scan(&n)
	f = append(f, 0)
	f = append(f, 1)
	f = append(f, 1)
	for f[len(f)-1] < 1e9 {
		i := len(f)
		f = append(f, f[i-1]+f[i-2])

	}

	for _, a := range f {
		for _, b := range f {
			for _, c := range f {
				if a+b+c == n {
					printf("%d %d %d\n", a, b, c)
					return
				}
			}
		}
	}
	printf("I'm too stupid to solve this problem\n")
}

func main() {
	startTime := time.Now()

	defer flush()

	var ntc int = 1
	//scan(&ntc)
	for t := 0; t < ntc; t++ {
		debug("\n====================================", t, "====================================")
		solve()
	}

	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
