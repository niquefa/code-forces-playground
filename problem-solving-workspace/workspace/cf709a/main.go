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

func solve() {
	var n, b, d int
	//read n b d
	scan(&n, &b, &d)
	var a = make([]int, n)
	for i := 0; i < n; i++ {
		scan(&a[i])
	}
	//fmt.Println(a)
	var ans int = 0
	var sum int = 0
	for i := 0; i < n; i++ {
		if a[i] <= b {
			sum += a[i]
			if sum > d {
				ans++
				sum = 0
			}
		}
	}
	fmt.Println(ans)
}

// ----------------------------- TEMPLATE END ----------------------------------

func main() {
	defer flush()
	solve()
}
