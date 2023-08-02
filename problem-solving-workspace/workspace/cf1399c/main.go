package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func flush()                            { out.Flush() }
func scan(a ...interface{})             { fmt.Fscan(in, a...) }
func printf(f string, a ...interface{}) { fmt.Fprintf(out, f, a...) }
func assert(f bool) {
	if !f {
		panic("gg")
	}
}

func solve() {
	var n int
	scan(&n)
	var w = make([]int, n)
	for i := 0; i < n; i++ {
		scan(&w[i])
	}
	if n == 1 {
		fmt.Println(0)
		return
	}
	sort.Ints(w)
	//fmt.Println(w)
	var maxValue = w[n-1] + w[n-2]
	maxPairs := 0
	for targetWeight := 2; targetWeight <= maxValue; targetWeight++ {
		var used = make([]bool, n)
		currentPairs := 0
		for i := 0; i < n; i++ {
			if used[i] {
				continue
			}
			for j := 0; j < n; j++ {
				if i == j || used[j] {
					continue
				}
				if w[i]+w[j] == targetWeight {
					used[i] = true
					used[j] = true
					currentPairs++
					break
				}
			}
		}

		if currentPairs > maxPairs {
			maxPairs = currentPairs
		}
	}
	fmt.Println(maxPairs)
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
