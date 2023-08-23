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
	var n int64
	scan(&n)
	if n%25 == 0 {
		fmt.Println(0)
		return
	}
	var nAsString string = fmt.Sprintf("%d", n)
	debug(nAsString)
	var nAsStringReverse string = ""
	for i := len(nAsString) - 1; i >= 0; i-- {
		nAsStringReverse += string(nAsString[i])
	}
	debug(nAsStringReverse)
	var x []string = []string{"00", "52", "05", "57"}
	var bestOption int = 100
	for _, candidate := range x {
		var firstIndex int = -1
		var secondIndex int = -1
		for i := 0; firstIndex == -1 && i < len(nAsStringReverse); i++ {
			if nAsStringReverse[i] == candidate[0] {
				firstIndex = i
				for j := i + 1; secondIndex == -1 && j < len(nAsStringReverse); j++ {
					if nAsStringReverse[j] == candidate[1] {
						secondIndex = j
					}
				}
			}
		}
		debug(firstIndex, secondIndex, candidate)
		if firstIndex == -1 || secondIndex == -1 {
			continue
		}
		if secondIndex-1 < bestOption {
			bestOption = secondIndex - 1
		}
	}
	fmt.Println(bestOption)
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
