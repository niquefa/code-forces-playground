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
	var a = make([]string, n)
	var b = make([][]bool, n)
	for i := 0; i < n; i++ {
		b[i] = make([]bool, n)
		scan(&a[i])
		for j := 0; j < n; j++ {
			if a[i][j] == '*' {
				b[i][j] = true
			}
		}
	}
	r0 := -1
	c0 := -1
	r1 := -1
	c1 := -1
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if a[i][j] == '*' {
				if r0 == -1 {
					r0 = i
					c0 = j
				} else {
					r1 = i
					c1 = j
				}
			}
		}
	}
	if r0 == r1 {
		if r0 == 0 {
			r1++
		} else {
			r1--
		}
		b[r1][c0] = true
		b[r1][c1] = true
	}
	if c0 == c1 {
		if c0 == 0 {
			c1++
		} else {
			c1--
		}
		b[r0][c1] = true
		b[r1][c1] = true
	}
	//fmt.Println(r0, c0, r1, c1)
	b[r0][c1] = true
	b[r1][c0] = true
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if b[i][j] {
				printf("*")
			} else {
				printf(".")
			}
		}
		printf("\n")
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
