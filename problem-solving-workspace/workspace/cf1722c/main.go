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
	var n int
	scan(&n)
	var wordsMap = map[string]int{}
	var players [3][]string
	for i := 0; i < 3; i++ {
		for j := 0; j < n; j++ {
			var s string
			scan(&s)
			wordsMap[s]++
			players[i] = append(players[i], s)
		}
	}
	var points [3]int
	for i := 0; i < 3; i++ {
		for _, s := range players[i] {
			if wordsMap[s] == 1 {
				points[i] += 3
			}
			if wordsMap[s] == 2 {
				points[i]++
			}
		}
	}
	for i := 0; i < 3; i++ {
		fmt.Printf("%d \n", points[i])
	}
	fmt.Println()
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
