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
func assert(f bool) {
	if !f {
		panic("gg")
	}
}

var ones = [10]int64{11111111111, 1111111111, 111111111, 11111111, 1111111, 111111, 11111, 1111, 111, 11}
var cache = map[int64]bool{}
var calculated = map[int64]bool{}

func f(n int64) bool {
	if n == 0 {
		return true
	}
	if n < 11 {
		return false
	}
	if calculated[n] {
		return cache[n]
	}
	calculated[n] = true

	for i := 0; i < len(ones); i++ {
		if n%ones[i] == 0 {
			cache[n] = true
			return true
		}
	}
	for i := 0; i < len(ones); i++ {
		if n >= ones[i] {
			if f(n - ones[i]) {
				cache[n] = true
				return true
			}
		}
	}
	cache[n] = false
	return false
}
func solve() {
	var n int64
	scan(&n)
	var yes = false
	for i := 0; i < len(ones); i++ {
		if n >= ones[i] {
			if f(n) {
				yes = true
				break
			}
		}

	}
	if yes {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

// ----------------------------- TEMPLATE END ----------------------------------
// Dynamic programming memoization
func main() {
	defer flush()

	var ntc int
	scan(&ntc)
	for t := 0; t < ntc; t++ {
		solve()
	}
}
