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
func getSumOfDigits(n int) int {
	sum := 0
	for {
		sum += n % 10
		n /= 10
		if n == 0 {
			break
		}
	}
	return sum
}
func solve() {
	var a int
	scan(&a)
	for {
		s := getSumOfDigits(a)
		if s%4 == 0 {
			fmt.Println(a)
			return
		}
		a++
	}

}

func main() {
	startTime := time.Now()

	defer flush()
	solve()
	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
