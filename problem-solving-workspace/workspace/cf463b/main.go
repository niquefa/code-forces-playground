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
	var a = make([]int, n+1)
	a[0] = 0
	for i := 1; i <= n; i++ {
		scan(&a[i])
	}
	var ans int = 0
	var energy int = 0
	for i := 1; i <= n; i++ {
		energy += a[i-1] - a[i]
		if energy < 0 {
			ans += -energy
			energy = 0
		}
	}
	fmt.Println(ans)
}

func main() {
	startTime := time.Now()

	defer flush()

	var ntc int = 1
	//scan(&ntc)
	for t := 0; t < ntc; t++ {

		solve()

	}

	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
