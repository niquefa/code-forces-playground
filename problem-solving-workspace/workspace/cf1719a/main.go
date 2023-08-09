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

func solve() {
	var n, m int
	scan(&n, &m)
	if n == 1 && m == 1 {
		fmt.Println("Tonya")
		return
	}
	if n == 1 {
		if (m-1)%2 == 0 {
			fmt.Println("Tonya")
		} else {
			fmt.Println("Burenka")
		}
		return
	}
	if ((m-1)%2 == 1 && (n-1)%2 == 0) || ((m-1)%2 == 0 && (n-1)%2 == 1) {
		fmt.Println("Burenka")
	} else {
		fmt.Println("Tonya")
	}

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
