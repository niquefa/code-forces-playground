package main

import (
	"bufio"
	"fmt"
	"os"
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
		panic("gg")
	}
}

func solve() {
	var n, m, x, y int
	scan(&n, &m, &x, &y)
	maze := make([]string, n)
	debug(n, m, x, y)
	for i := 0; i < n; i++ {
		scan(&maze[i])
		debug(maze[i])
	}
	costUsingSize2Tiles := 0
	costUsingSize1Tiles := 0

	painted := make([][]bool, n)
	for i := range painted {
		painted[i] = make([]bool, m)
	}
	// use 2 tiles

	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if maze[i][j] == '.' {
				costUsingSize1Tiles += x
			}
			if painted[i][j] {
				continue
			}
			if j+1 < m && maze[i][j] == '.' && maze[i][j+1] == '.' {
				costUsingSize2Tiles += y
				painted[i][j] = true
				painted[i][j+1] = true
			}
			if maze[i][j] == '.' && !painted[i][j] {
				costUsingSize2Tiles += x
				painted[i][j] = true
			}
		}
	}

	answer := costUsingSize1Tiles
	if costUsingSize1Tiles > costUsingSize2Tiles {
		answer = costUsingSize2Tiles
	}
	fmt.Println(answer)
}

// ----------------------------- TEMPLATE END ----------------------------------

func main() {
	defer flush()

	var ntc int
	scan(&ntc)
	for t := 0; t < ntc; t++ {
		solve()
	}
}
