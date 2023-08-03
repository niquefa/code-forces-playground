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
	var a = make([]int, n)
	for i := 0; i < n; i++ {
		scan(&a[i])
	}
	used := make([]bool, 1001)
	answer := []int{}
	for i := n - 1; i >= 0; i-- {
		if !used[a[i]] {
			answer = append(answer, a[i])
			used[a[i]] = true
		}
	}
	fmt.Println(len(answer))
	for i := len(answer) - 1; i >= 0; i-- {
		fmt.Print(answer[i], " ")
	}
	fmt.Println()
}

// ----------------------------- TEMPLATE END ----------------------------------

func main() {
	defer flush()
	solve()
}
