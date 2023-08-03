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
	var n int64
	scan(&n)
	if n <= 6 {
		printf("15\n")
		return
	}
	if n <= 8 {
		printf("20\n")
		return
	}
	if n <= 10 {
		printf("25\n")
		return
	}
	//22520532760919150
	//22520532760919155
	if n%2 == 1 {
		n++
	}
	var ans int64 = 2*n + n/2
	//var ans int64 = int64(math.Ceil(float64(n) * 2.5))
	for ans%5 != 0 {
		debug("++", ans)
		ans++
	}

	printf("%v\n", ans)
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
