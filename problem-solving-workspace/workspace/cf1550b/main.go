package main

import (
	"bufio"
	"fmt"
	"os"
	"regexp"
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
func filterNonEmptyStrings(strs []string) []string {
	var result []string
	for _, s := range strs {
		if len(s) > 0 {
			result = append(result, s)
		}
	}
	return result
}
func solve() {
	var n, a, b int
	var s string
	scan(&n, &a, &b, &s)
	if b >= 0 {
		fmt.Println(a*n + b*n)
		return
	}

	ones := filterNonEmptyStrings(regexp.MustCompile("0+").Split(s, -1))
	zeroes := filterNonEmptyStrings(regexp.MustCompile("1+").Split(s, -1))
	debug(zeroes, ones)
	debug(len(zeroes), len(ones))

	k := 1 + ((len(ones) + len(zeroes)) / 2)

	fmt.Println(a*n + b*k)
}

func main() {
	startTime := time.Now()

	defer flush()

	var ntc int
	scan(&ntc)
	for t := 0; t < ntc; t++ {

		solve()

	}

	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
