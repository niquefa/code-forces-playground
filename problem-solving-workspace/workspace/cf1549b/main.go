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
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func min(a, b int) int {
	if b > a {
		return a
	}
	return b
}
func solve() {
	var n int
	var a, b string
	scan(&n, &a, &b)
	var ans int = 0
	a = "2" + a + "2"
	b = "2" + b + "2"
	for i := 1; i <= n; i++ {
		if a[i] == '0' && b[i] == '1' {
			ans++
		}
	}
	var toTheLeft int = 0
	var used = make([]bool, n+2)
	//debug(a)
	//debug(b)
	for i := 1; i <= n; i++ {
		if a[i] == '0' || b[i] == '0' {
			//debug("NO USE", i)
		} else if a[i-1] == '1' && !used[i-1] {
			toTheLeft++
			used[i-1] = true
		} else if a[i+1] == '1' && !used[i+1] {
			used[i+1] = true
			toTheLeft++
		}
		//debug(i, toTheLeft, used)
	}
	var toTheRight int = 0
	used = make([]bool, n+2)
	for i := n; i >= 1; i-- {
		if a[i] == '0' || b[i] == '0' {
			//debug("NO USE", i)
		} else if a[i+1] == '1' && !used[i+1] {
			toTheRight++
			used[i+1] = true
		} else if a[i-1] == '1' && !used[i-1] {
			used[i-1] = true
			toTheRight++
		}
		//debug(i, toTheRight, used)
	}
	debug(ans, toTheLeft, toTheRight)
	fmt.Println(ans + max(toTheLeft, toTheRight))

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
