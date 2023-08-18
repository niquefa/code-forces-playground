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
func getDigitSum(n int) int {
	var ans int = 0
	for n > 0 {
		ans += n % 10
		n /= 10
	}
	return ans
}
func solve() {
	var n int
	scan(&n)
	var k int = 0
	debug(n)
	for x := 1; ; x++ {
		if getDigitSum(x) == 10 {
			k++
			//debug(k, x)
		}
		if k == n {
			fmt.Println(x)
			break
		}
	}

}

func main() {
	startTime := time.Now()

	defer flush()

	var ntc int = 1
	//scan(&ntc)
	for t := 0; t < ntc; t++ {

		solve()

	}

	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
