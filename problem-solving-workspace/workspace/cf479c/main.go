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
func assert(f bool) {
	if !f {
		panic("gg")
	}
}

type Tuple struct {
	First  int
	Second int
}

func solve() {
	var n int
	scan(&n)
	var a, b int
	tuples := make([]Tuple, n)
	for i := 0; i < n; i++ {
		scan(&a)
		scan(&b)
		tuples[i] = Tuple{a, b}
	}

	sort.Slice(tuples, func(i, j int) bool {
		if tuples[i].First == tuples[j].First {
			return tuples[i].Second < tuples[j].Second
		}
		return tuples[i].First < tuples[j].First
	})

	// fmt.Println("Sorted array of tuples:")
	// for _, t := range tuples {
	// 	fmt.Printf("(%d, %d)\n", t.First, t.Second)
	// }
	var currentDay int = 1
	for i := 0; i < n; i++ {
		if currentDay <= tuples[i].Second {
			currentDay = tuples[i].Second
		} else {
			currentDay = tuples[i].First
		}
		//fmt.Printf("currentDay: %d\n", currentDay)
	}
	fmt.Println(currentDay)
}

// ----------------------------- TEMPLATE END ----------------------------------

func main() {
	defer flush()
	solve()
}
