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
func pow(a, b int64) int64 {
	if b == 0 {
		return 1
	}
	if b == 1 {
		return a
	}
	var x = pow(a, b/2)
	if b%2 == 0 {
		return x * x
	}
	return x * x * a
}
func solve() {
	var x1, p1, x2, p2 int
	scan(&x1, &p1, &x2, &p2)
	if p1 == p2 {
		if x1 == x2 {
			fmt.Println("=")
		} else if x1 > x2 {
			fmt.Println(">")
		} else {
			fmt.Println("<")
		}
		return
	}
	if p1 > p2 {
		p1 = p1 - p2
		p2 = 0
	} else {
		p2 = p2 - p1
		p1 = 0
	}
	var s1 string = fmt.Sprintf("%d", x1)
	var s2 string = fmt.Sprintf("%d", x2)
	if len(s1)+p1 < len(s2)+p2 {
		fmt.Println("<")
		return
	}
	if len(s1)+p1 > len(s2)+p2 {
		fmt.Println(">")
		return
	}
	var a = int64(x1) * int64(pow(10, int64(p1)))
	var b = int64(x2) * int64(pow(10, int64(p2)))
	if a == b {
		fmt.Println("=")
	}
	if a > b {
		fmt.Println(">")
	}
	if a < b {
		fmt.Println("<")
	}

}

func main() {
	startTime := time.Now()

	defer flush()

	var ntc int = 1
	scan(&ntc)
	for t := 0; t < ntc; t++ {
		debug("\n====================================", t, "====================================")
		solve()
	}

	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
