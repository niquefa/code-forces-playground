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

func solve() {
	var n, k int
	var s string
	scan(&n, &k, &s)
	if k == 26 {
		fmt.Println(int64(n) * int64(n+1) / 2)
		return
	}
	var notInS string = ""
	var inS string
	var validChars string = ""
	for i := 0; i < k; i++ {
		scan(&inS)
		validChars += inS
	}
	for c := 'a'; c <= 'z'; c++ {
		if !regexp.MustCompile(fmt.Sprintf("[%c]", c)).MatchString(validChars) {
			notInS += string(c)
		}
	}
	parts := regexp.MustCompile(fmt.Sprintf("[%s]+", notInS)).Split(s, -1)
	var ans int64 = 0
	for _, part := range parts {
		if len(part) > 0 {
			ans += int64(len(part) * (len(part) + 1) / 2)
		}
	}
	fmt.Println(ans)
}

func main() {
	startTime := time.Now()

	defer flush()

	var ntc int = 1
	for t := 0; t < ntc; t++ {
		debug("\n====================================", t, "====================================")
		solve()
	}

	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
