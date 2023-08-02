package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
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
	var s string
	scan(&s)
	sLowerCase := strings.ToLower(s)
	//fmt.Println(sLowerCase)
	f := true
	lowestIndex := make(map[rune]int)
	biggestIndex := make(map[rune]int)
	for index, c := range sLowerCase {
		if c != 'm' && c != 'e' && c != 'o' && c != 'w' {
			f = false
			break
		}
		// check if c is in lowest index
		if _, ok := lowestIndex[c]; !ok {
			lowestIndex[c] = index
		}
		biggestIndex[c] = index
	}
	if !f || len(lowestIndex) != 4 {
		fmt.Println("NO")
		return
	}
	// for _, c := range "meow" {
	// 	fmt.Println(c, lowestIndex[c], biggestIndex[c])
	// }
	if biggestIndex['m'] > lowestIndex['e'] ||
		biggestIndex['e'] > lowestIndex['o'] ||
		biggestIndex['o'] > lowestIndex['w'] {
		fmt.Println("NO")
	} else {
		fmt.Println("YES")
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
