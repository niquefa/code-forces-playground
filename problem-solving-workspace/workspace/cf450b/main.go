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
		panic("gg Rafa, something went wrong!")
	}
}

// ----------------------------- TEMPLATE END ----------------------------------
var cache = make(map[int64]int64)
var x, y, n int64

const MOD = 1000000007

func f(i int64) int64 {
	if i == 1 {
		ans := x
		if ans < 0 {
			ans += MOD
		}
		return ans
	}
	if i == 2 {
		ans := y
		if ans < 0 {
			ans += MOD
		}
		return ans
	}
	if i == 3 {
		ans := y - x
		if ans < 0 {
			ans += MOD
		}
		return ans
	}
	if savedValue, ok := cache[i]; ok {
		return savedValue
	}

	var a int64 = f(i - 1)
	if a < 0 {
		a += MOD
	}
	var b int64 = f(i - 2)
	if b < 0 {
		b += MOD
	}
	ans := (a%MOD - b%MOD)
	if ans < 0 {
		ans += MOD
	}
	ans %= MOD
	cache[i] = ans
	return ans
}

func solve() {
	scan(&x, &y, &n)

	for i := int64(1); i <= 12; i++ {
		debug(i, f(i))
	}
	fmt.Println(f(n%6 + 6))
}

func main() {
	defer flush()
	solve()
}
