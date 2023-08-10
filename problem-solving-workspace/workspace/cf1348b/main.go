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
	var n, k int
	scan(&n, &k)
	var b = make([]int, n)
	var distinct = make(map[int]bool)
	for i := 0; i < n; i++ {
		scan(&b[i])
		distinct[b[i]] = true
	}
	//fmt.Println(n, k, b, distinct, len(distinct), len(distinct) > k)
	if len(distinct) > k {
		fmt.Println(-1)
		return
	}
	var firsts = make(map[int]bool)
	var firstsAsArray []int
	for _, v := range b {
		if len(firsts) == len(distinct) {
			break
		}
		if firsts[v] {
			continue
		}
		firsts[v] = true
		firstsAsArray = append(firstsAsArray, v)
	}
	for len(firstsAsArray) < k {
		firstsAsArray = append(firstsAsArray, 1)
	}
	var ans []int
	for len(ans) < n*k {
		//debug(n, k, ans)
		ans = append(ans, firstsAsArray...)
	}

	//debug(firsts, firstsAsArray)
	//debug(ans)
	fmt.Println(len(ans))
	for i := 0; i < len(ans); i++ {
		fmt.Print(ans[i], " ")
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
