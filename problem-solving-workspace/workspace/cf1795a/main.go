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
func ok(s string) bool {
	for i := 1; i < len(s); i++ {
		if s[i] == s[i-1] {
			return false
		}
	}
	return true
}
func f(a, b string) bool {
	for {
		if ok(a) && ok(b) {
			return true
		}
		if len(a) < 2 {
			break
		}
		lastAChar := a[len(a)-1]
		a = a[:len(a)-1]
		b = b + string(lastAChar)
	}

	return false
}
func solve() {
	var n, m int
	var a, b string
	scan(&n, &m, &a, &b)
	debug(n, m, a, b)
	if ok(a) && ok(b) {
		fmt.Println("YES")
		return
	}
	var originalA = string(a)
	var originalB = string(b)
	if f(originalA, originalB) || f(originalB, originalA) {
		fmt.Println("YES")
		return
	}
	fmt.Println("NO")
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
