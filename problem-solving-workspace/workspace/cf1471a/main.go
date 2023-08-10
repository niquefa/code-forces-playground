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
	var n, x int
	scan(&n, &x)
	var a = make([]int, n)
	for i := 0; i < n; i++ {
		scan(&a[i])
	}
	smallBeauty := 0
	minBeauty := 0
	for i := 0; i < n; i++ {
		smallBeauty += a[i] / x
		if a[i]%x != 0 {
			smallBeauty++
		}
		minBeauty += a[i]
	}
	minBeauty = (minBeauty + x - 1) / x
	fmt.Println(minBeauty, smallBeauty)
}

func main() {
	startTime := time.Now()

	defer flush()

	var ntc int
	scan(&ntc)
	for t := 0; t < ntc; t++ {

		solve()

	}

	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
