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
	var n, m, r, c int
	scan(&n, &m, &r, &c)
	var matrix = make([]string, n)
	for i := 0; i < n; i++ {
		scan(&matrix[i])
	}
	existsCellWithB := false
	for i := 0; i < n; i++ {
		//debug(matrix[i])
		for j := 0; j < m; j++ {
			if matrix[i][j] == 'B' {
				existsCellWithB = true
			}
		}
	}
	//debug(n, m, r, c, existsCellWithB)
	if !existsCellWithB {
		fmt.Println(-1)
		return
	}
	r--
	c--
	if matrix[r][c] == 'B' {
		fmt.Println(0)
		return
	}
	for row := 0; row < n; row++ {
		if matrix[row][c] == 'B' {
			fmt.Println(1)
			return
		}
	}
	for col := 0; col < m; col++ {
		if matrix[r][col] == 'B' {
			fmt.Println(1)
			return
		}
	}
	fmt.Println(2)

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
