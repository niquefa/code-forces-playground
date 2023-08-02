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
	var n, m int
	scan(&n, &m)
	var a = make([]string, n)

	// Read input lines using the 'in' bufio.Reader
	for i := 0; i < n; i++ {
		scan(&a[i])
		//fmt.Println(a[i])
	}

	//fmt.Println(n, m, a, len(a))
	for i, str := range a {
		//fmt.Println(i, str)
		for j, ch := range str {
			//fmt.Println(i, j, ch)
			if ch == '.' {
				if (i+j)%2 == 0 {
					fmt.Print("B")
				} else {
					fmt.Print("W")
				}
			} else {
				fmt.Print("-")
			}
		}
		fmt.Println()
	}
}

// ----------------------------- TEMPLATE END ----------------------------------

func main() {
	defer flush()

	solve()
}
