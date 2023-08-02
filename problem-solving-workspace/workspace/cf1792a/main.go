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
	var n int
	scan(&n)
	var a = make([]int, 0)
	var ones int = 0
	for i := 0; i < n; i++ {
		var tmp int
		scan(&tmp)
		if tmp > 1 {
			a = append(a, tmp)
		}
		if tmp == 1 {
			ones++
		}
	}
	//fmt.Println(a)
	fmt.Println(len(a) + ones/2 + ones%2)
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
