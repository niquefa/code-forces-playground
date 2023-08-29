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
func abs(x int64) int64 {
	if x < 0 {
		return -x
	}
	return x
}
func f(x0, n int64) int64 {
	var i int64
	var x int64 = x0
	if n <= 8 {
		for i = 1; i <= int64(n); i++ {
			var dir int64 = 1
			if x%2 == 0 {
				dir = -1
			}
			x = x + dir*i
		}
		return x
	}
	if n%4 == 0 {
		return x0
	}
	if x0 < 0 {
		if abs(x0)%2 == 1 {
			//debug("Negative odd", x0, n)
			if (n-1)%4 == 0 {
				return x0 + n
			}

			if (n-2)%4 == 0 {
				return x0 - 1
			}

			if (n-3)%4 == 0 {
				return x0 - n - 1
			}
			return x0
		}
		if (n-1)%4 == 0 {
			return x0 - n
		}

		if (n-2)%4 == 0 {
			return x0 + 1
		}

		if (n-3)%4 == 0 {
			return x0 + n + 1
		}
		return x0
	}
	if x0%2 == 1 {
		if (n-1)%4 == 0 {
			return x0 + n
		}

		if (n-2)%4 == 0 {
			return x0 - 1
		}

		if (n-3)%4 == 0 {
			return x0 - n - 1
		}
	}
	if (n-1)%4 == 0 {
		return x0 - n
	}

	if (n-2)%4 == 0 {
		return x0 + 1
	}

	if (n-3)%4 == 0 {
		return x0 + n + 1
	}
	return x0
}
func solve() {
	var n, x0 int64
	scan(&x0, &n)
	fmt.Println(f(x0, n))
	// var x int64 = x0
	// var i int64
	// for i = 1; i <= int64(n); i++ {
	// 	var dir int64 = 1
	// 	if x%2 == 0 {
	// 		dir = -1
	// 	}
	// 	x = x + dir*i
	// 	debug(i, x, x0-x, f(x0, i))
	// }
	// debug(x)
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
