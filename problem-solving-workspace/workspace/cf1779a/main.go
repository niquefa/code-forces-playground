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
	var s string
	scan(&s)
	var indexLastL = -1
	var indexFirstR = -1
	for i := 0; i < n; i++ {
		if s[i] == 'L' {
			indexLastL = i
		}
		if s[i] == 'R' && indexFirstR == -1 {
			indexFirstR = i
		}
	}
	debug(indexFirstR, indexLastL)
	if indexFirstR == -1 || indexLastL == -1 {
		fmt.Println(-1)
		return
	}
	for i := 0; i < n-1; i++ {
		if s[i] == 'L' && s[i+1] == 'R' {
			fmt.Println(i + 1)
			return
		}
		if s[i] == 'R' && s[i+1] == 'L' {
			fmt.Println(0)
			return
		}
	}
	fmt.Println(-1)
}

func main() {
	startTime := time.Now()

	defer flush()

	var ntc int = 1
	scan(&ntc)
	for t := 0; t < ntc; t++ {
		debug("\n====================================", t, "====================================")
		solve()
	}

	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
