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
	if n <= 2 {
		fmt.Println(s)
		return
	}
	var b string = ""
	for i := len(s) - 1; i >= 0; i -= 2 {
		b = string(s[i]) + b
	}
	var a string = ""
	for i := len(s) - 2; i >= 0; i -= 2 {
		a += string(s[i])
	}
	debug(a, b)
	fmt.Println(a + b)
}

func main() {
	startTime := time.Now()
	defer flush()
	solve()
	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
