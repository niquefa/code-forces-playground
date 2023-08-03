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

var factors = make([]int64, 0, 1000)

func solve() {
	var n int64
	scan(&n)
	var ans int = 0
	for _, factor := range factors {
		if n == 0 {
			break
		}
		if n >= factor {
			ans += int(n / factor)
			n %= factor
		}
	}
	if n != 0 {
		ans = -1
	}
	fmt.Println(ans)
}

// ----------------------------- TEMPLATE END ----------------------------------

func main() {
	defer flush()
	var factor int64 = 2050
	for {
		if factor > 1000000000000000000 {
			break
		}
		factors = append([]int64{factor}, factors...)
		factor *= 10
	}
	debug(factors)
	debug(len(factors))
	var ntc int
	scan(&ntc)
	for t := 0; t < ntc; t++ {
		solve()
	}
}
