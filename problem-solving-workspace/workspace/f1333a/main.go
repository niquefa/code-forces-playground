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
var n, m int

var solution [][]bool

func create() {
	solution = make([][]bool, n)
	for i := range solution {
		solution[i] = make([]bool, m)
		for j := range solution[i] {
			solution[i][j] = true
		}
	}
}
func printSolution() {
	for i := range solution {
		for j := range solution[i] {
			if solution[i][j] {
				printf("B")
			} else {
				printf("W")
			}
		}
		printf("\n")
	}
}
func solve() {

	scan(&n, &m)
	create()
	debug("n,m", n, m)
	solution[0][0] = false
	printSolution()
}

func main() {
	startTime := time.Now()

	defer flush()

	var ntc int
	scan(&ntc)
	for t := 0; t < ntc; t++ {
		debug("Test", t)
		solve()

	}

	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
