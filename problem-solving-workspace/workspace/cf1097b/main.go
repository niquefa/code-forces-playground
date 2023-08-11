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
	scan(&n)
	var a = make([]int, n)
	for i := 0; i < n; i++ {
		scan(&a[i])
	}
	var limit = 1 << n
	var possible = false
	//fmt.Println(n, a)
	for mask := 0; mask < limit; mask++ {
		var degrees int = 0
		for i := 0; i < n; i++ {
			if mask&(1<<i) != 0 {
				degrees += a[i]
			} else {
				degrees -= a[i]
			}
			if degrees < 0 {
				degrees = 360 + degrees
			}
			degrees %= 360
		}
		if degrees == 0 {
			possible = true
			break
		}
		//fmt.Printf("%d\t%b\t%d\n", mask, mask, degrees)
	}
	if possible {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

func main() {
	startTime := time.Now()

	defer flush()
	solve()

	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
