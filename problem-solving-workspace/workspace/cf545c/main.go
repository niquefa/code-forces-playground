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
func max(values ...int) int {
	ans := values[0]
	for _, v := range values[1:] {
		if v > ans {
			ans = v
		}
	}
	return ans
}

const MAX = 100003
const LEFT = 0
const RIGHT = 1
const STAY = 2

var cache [MAX][3]int
var n int
var x [MAX]int
var h [MAX]int

// DP Dynamic programming memoization
func f(i, action int) int {
	if i == 0 {
		return 1
	}
	if i == n-1 {
		return 1 + max(f(i-1, LEFT), f(i-1, STAY), f(i-1, RIGHT))
	}
	if cache[i][action] != -1 {
		return cache[i][action]
	}
	var returnValue int = 0
	if action == STAY {
		returnValue = max(f(i-1, LEFT), f(i-1, STAY), f(i-1, RIGHT))
	} else if action == LEFT {
		if x[i]-h[i] <= x[i-1] {
			return 0
		}
		ansRight := 0
		if x[i-1]+h[i-1] < x[i]-h[i] {
			ansRight = f(i-1, RIGHT)
		}
		returnValue = max(ansRight, f(i-1, STAY), f(i-1, LEFT)) + 1
	} else if action == RIGHT {
		if x[i]+h[i] >= x[i+1] {
			return 0
		}
		returnValue = max(f(i-1, LEFT), f(i-1, STAY), f(i-1, RIGHT)) + 1
	}
	cache[i][action] = returnValue
	return cache[i][action]
}

func solve() {
	scan(&n)
	for i := 0; i <= n; i++ {
		for j := 0; j < 3; j++ {
			cache[i][j] = -1
		}
	}
	for i := 0; i < n; i++ {
		scan(&x[i], &h[i])
	}
	fmt.Println(f(n-1, RIGHT))
}

func main() {
	startTime := time.Now()
	defer flush()
	solve()
	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
