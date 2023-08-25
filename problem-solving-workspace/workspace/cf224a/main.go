package main

import (
	"bufio"
	"fmt"
	"math"
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
	var a, b, c int64
	scan(&a, &b, &c)
	x := math.Sqrt(float64((a * b) / c))
	y := math.Sqrt(float64((c * b) / a))
	z := math.Sqrt(float64((a * c) / b))
	debug(x, y, z)
	sumOfEdges := 4 * (x + y + z)
	fmt.Print(sumOfEdges)
}

func main() {
	startTime := time.Now()

	defer flush()

	solve()

	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
