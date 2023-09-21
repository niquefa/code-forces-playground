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
func toSlice(s string) []rune {
	return []rune(s)
}
func solve() {
	var x string
	scan(&x)
	if "abc" == x {
		fmt.Println("YES")
		return
	}
	var from [3]int = [3]int{0, 0, 1}
	var to [3]int = [3]int{1, 2, 2}
	debug(x, "x")
	for i := 0; i < 3; i++ {
		sx := toSlice(x)
		sx[from[i]], sx[to[i]] = sx[to[i]], sx[from[i]]
		if string(sx) == "abc" {
			fmt.Println("YES")
			return
		}
	}

	fmt.Println("NO")
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
