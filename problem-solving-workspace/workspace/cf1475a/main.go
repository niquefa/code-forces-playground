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
	var s string
	scan(&n, &s)
	var prev int
	if s[0] == '0' {
		prev = 1
		fmt.Print(1)
	} else {
		prev = 2
		fmt.Print(1)
	}

	for i := 1; i < n; i++ {
		if prev == 2 {
			if s[i] == '0' {
				prev = 1
				fmt.Print(1)
			} else {
				prev = 1
				fmt.Print(0)
			}
		} else if prev == 1 {
			if s[i] == '1' {
				prev = 2
				fmt.Print(1)
			} else {
				prev = 0
				fmt.Print(0)
			}
		} else if prev == 0 {
			if s[i] == '0' {
				prev = 1
				fmt.Print(1)
			} else {
				prev = 2
				fmt.Print(1)
			}
		}

	}
	fmt.Println()
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
