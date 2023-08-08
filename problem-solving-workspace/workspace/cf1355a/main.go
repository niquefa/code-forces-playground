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
func getMinMaxDigit(n int64) (min int64, max int64) {
	min = n % 10
	max = n % 10
	for n > 0 {
		d := n % 10
		if d < min {
			min = d
		}
		if d > max {
			max = d
		}
		n /= 10
	}
	return
}

var a1, k int64

func a(n int64) int64 {
	if n == 1 {
		return a1
	}
	min, max := getMinMaxDigit(a(n - 1))
	a_n1 := a(n - 1)
	return a_n1 + min*max
}

func bruteForce(a1, k int64) {
	debug("Bruting Forcing..")
	for i := int64(2); i < 100; i++ {
		ak := a(i)
		ak_1 := a(i - 1)
		debug(i, ak, i-1, ak_1, ak-ak_1)
		if ak-ak_1 == 0 {
			break
		}
	}
}
func solve() {
	var a int64
	scan(&a1, &k)
	//debug(a1, k)
	//bruteForce(a1, k)
	k--
	a = a1
	for k > 0 {
		k--
		min, max := getMinMaxDigit(a)
		toAdd := min * max
		if toAdd == 0 {
			break
		}
		a += toAdd
	}
	fmt.Println(a)
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
