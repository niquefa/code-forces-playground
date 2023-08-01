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

// ----------------------------- TEMPLATE END ----------------------------------

func solve() {
	var a string
	scan(&a)
	var b string
	scan(&b)
	var c string = a + b
	//fmt.Println(c)
	set := make(map[rune]bool)
	for _, ch := range c {
		set[ch] = true
	}
	var n int = len(set)
	fmt.Println(n - 1)
}

func main() {
	defer flush()

	var ntc int
	scan(&ntc)
	for t := 0; t < ntc; t++ {
		solve()
	}
}
