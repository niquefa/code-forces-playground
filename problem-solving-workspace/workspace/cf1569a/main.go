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
	var n int
	var s string
	scan(&n, &s)

	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			frequency := make(map[byte]int)
			for k := i; k <= j; k++ {
				frequency[s[k]]++
			}
			//debug(i, j, frequency)
			//debug(frequency)
			if len(frequency) < 2 {
				continue
			}
			if frequency['a'] == frequency['b'] {
				fmt.Println(i+1, j+1)
				return
			}
		}
	}
	fmt.Println(-1, -1)

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
