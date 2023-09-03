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
	var r, g, b, w int
	scan(&r, &g, &b, &w)
	if r%2+g%2+b%2+w%2 <= 1 {
		printf("Yes\n")
		return
	}
	if r%2+g%2+b%2+w%2 == 4 {
		printf("Yes\n")
		return
	}
	r--
	g--
	b--
	w += 3
	if r < 0 || g < 0 || b < 0 {
		printf("No\n")
		return
	}
	if r%2+g%2+b%2+w%2 <= 1 {
		printf("Yes\n")
		return
	}
	printf("No\n")
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
