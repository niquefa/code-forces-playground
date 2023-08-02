package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
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

const char1 = '1'
const char2 = '2'
const n = 9

var a = make([]string, n)

func solve() {

	for i := 0; i < n; i++ {
		scan(&a[i])
	}
	for _, str := range a {
		result := strings.ReplaceAll(str, string(char1), string(char2))
		fmt.Println(result)
	}
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
