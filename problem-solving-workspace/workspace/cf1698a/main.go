package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func flush()                            { out.Flush() }
func scan(a ...interface{})             { fmt.Fscan(in, a...) }
func printf(f string, a ...interface{}) { fmt.Fprintf(out, f, a...) }
func assert(f bool) {
	if !f {
		panic("gg")
	}
}

func solve() {
	var n int
	scan(&n)
	var a = make([]int, n)
	for i := 0; i < n; i++ {
		scan(&a[i])
	}

	for i := 0; i < n; i++ {
		var target_mask int = a[i]
		//create empty int array
		var mask int = -1
		for j := 0; j < n; j++ {
			if i == j {
				continue
			}
			if mask == -1 {
				mask = a[j]
			} else {
				mask ^= a[j]
			}
		}
		if mask == target_mask {
			printf("%d\n", mask)
			return
		}
	}
}

// ----------------------------- TEMPLATE END ----------------------------------

func main() {
	defer flush()

	var ntc int
	scan(&ntc)
	for t := 0; t < ntc; t++ {
		solve()
	}
}
