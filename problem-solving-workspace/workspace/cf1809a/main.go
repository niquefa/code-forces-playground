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
	var s string
	scan(&s)
	var runeSet = make(map[rune]int)
	var threeAndOne bool = false
	for _, r := range s {
		runeSet[r]++
		if runeSet[r] == 3 {
			threeAndOne = true
		}
	}
	if len(runeSet) == 1 {
		fmt.Println(-1)
		return
	}
	if len(runeSet) == 4 {
		fmt.Println(4)
		return
	}
	if threeAndOne {
		fmt.Println(6)
		return
	}
	fmt.Println(4)
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
