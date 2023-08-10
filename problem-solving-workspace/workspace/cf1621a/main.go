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
	var n, rooks int
	scan(&n, &rooks)
	used := [][]bool{}
	hasRook := [][]bool{}

	for i := 0; i < n; i++ {
		used = append(used, make([]bool, n))
		hasRook = append(hasRook, make([]bool, n))
	}
	//fmt.Println(n, rooks, used)
	//debug(n, rooks, used)
	for i := 0; i < n && rooks > 0; i++ {
		for j := 0; j < n && rooks > 0; j++ {
			if used[i][j] {
				continue
			}
			used[i][j] = true
			hasRook[i][j] = true
			rooks--
			for k := i; k < n; k++ {
				used[i][k] = true
			}
			for k := j; k < n; k++ {
				used[k][j] = true
			}
			if i+1 < n {
				for k := j; k < n; k++ {
					used[i+1][k] = true
				}
			}
			if j+1 < n {
				for k := j; k < n; k++ {
					used[k][j+1] = true
				}
			}
		}
	}
	if rooks > 0 {
		fmt.Println(-1)
		return
	}
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if hasRook[i][j] {
				fmt.Print("R")
			} else {
				fmt.Print(".")
			}
		}
		fmt.Println()
	}
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
