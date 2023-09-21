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
func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}
func dist(r1, c1, r2, c2 int) int {
	return abs(r1-r2) + abs(c1-c2)
}
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func solve() {
	var a = make([]string, 10)
	for i := 0; i < 10; i++ {
		scan(&a[i])
	}

	var points = 0
	for i := 0; i < 10; i++ {
		for j := 0; j < 10; j++ {
			if a[i][j] == 'X' {
				minDist := 100
				minDist = min(minDist, dist(i, j, i, -1))
				minDist = min(minDist, dist(i, j, i, 10))
				minDist = min(minDist, dist(i, j, -1, j))
				minDist = min(minDist, dist(i, j, 10, j))
				points += minDist

			}
		}
	}

	fmt.Println(points)
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
