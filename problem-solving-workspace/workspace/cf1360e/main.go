package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
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
	var n int
	scan(&n)
	var a = make([]string, n)
	for i := 0; i < n; i++ {
		scan(&a[i])
		a[i] += "1"
	}
	a = append(a, strings.Repeat("1", n+1))
	//fmt.Println(a)
	//debug(a)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if a[i][j] == '1' && a[i+1][j] == '0' && a[i][j+1] == '0' {
				fmt.Println("NO")
				return
			}
		}
	}
	fmt.Println("YES")
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
