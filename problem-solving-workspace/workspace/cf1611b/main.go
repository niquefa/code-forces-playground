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
func debug(a ...interface{}) {
	fmt.Fprintln(os.Stderr, a...)
}
func solve() {
	var a, b int
	scan(&a, &b)
	var maxTeams int = a
	if b < a {
		maxTeams = b
	}
	var peopleLeft int = a + b - 2*maxTeams
	//debug(a, b, maxTeams, peopleLeft)
	if peopleLeft >= 2*maxTeams {
		fmt.Println(maxTeams)
		return
	}
	fmt.Println((a + b) / 4)

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
