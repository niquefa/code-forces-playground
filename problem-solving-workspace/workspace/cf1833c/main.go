package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
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
	var oddCount = 0
	var evenCount = 0
	var lowestOdd = 1000000000
	for i := 0; i < n; i++ {
		scan(&a[i])
		if a[i]%2 == 0 {
			evenCount++
		} else {
			oddCount++
			if a[i] < lowestOdd {
				lowestOdd = a[i]
			}
		}
	}
	debug(a)
	if oddCount == n || evenCount == n {
		fmt.Println("YES")
		return
	}
	sort.Ints(a)
	for i := 1; i < n; i++ {
		if a[0]%2 == 0 {
			if a[i]%2 == 1 {
				a[i] -= lowestOdd
			}
		} else {
			if a[i]%2 == 0 {
				a[i] -= lowestOdd
			}
		}
		if a[i] <= 0 {
			fmt.Println("NO")
			return
		}
	}
	fmt.Println("YES")
}

func main() {
	defer flush()

	var ntc int
	scan(&ntc)
	for t := 0; t < ntc; t++ {
		solve()
	}
}
