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
	var setOfRunes = make(map[rune]bool)
	for _, r := range s {
		setOfRunes[r] = true
	}
	if len(setOfRunes) == 1 {
		fmt.Println(s)
		return
	}
	if s[0] == '0' {
		for i := 0; i < len(s); i++ {
			fmt.Print("01")
		}
	} else {
		for i := 0; i < len(s); i++ {
			fmt.Print("10")
		}
	}
	fmt.Println()

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
