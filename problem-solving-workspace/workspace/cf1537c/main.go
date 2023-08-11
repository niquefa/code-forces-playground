package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
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
func getDifficultyScore(h []int) int {
	ans := 0
	for i := 1; i < len(h); i++ {
		if h[i]-h[i-1] >= 0 {
			ans++
		}
	}
	return ans
}
func solve() {
	var n int
	scan(&n)
	var h = make([]int, n)
	for i := 0; i < n; i++ {
		scan(&h[i])
	}
	sort.Ints(h)
	if n == 2 {
		fmt.Println(h[0], h[1])
		return
	}

	var leftBorderIndex = 0
	var rightBorderIndex = 1
	var minDiff = h[rightBorderIndex] - h[leftBorderIndex]
	for i := 2; i < n; i++ {
		if h[i]-h[i-1] < minDiff {
			minDiff = h[i] - h[i-1]
			leftBorderIndex = i - 1
			rightBorderIndex = i
		}
	}
	var answer = make([]int, n)
	answer[0] = h[leftBorderIndex]
	answer[n-1] = h[rightBorderIndex]
	var j = 1
	for i := rightBorderIndex + 1; i < n; i++ {
		answer[j] = h[i]
		j++
	}
	for i := 0; i < leftBorderIndex; i++ {
		answer[j] = h[i]
		j++
	}
	for i := 0; i < n; i++ {
		fmt.Print(answer[i], " ")
	}
	fmt.Println()
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
