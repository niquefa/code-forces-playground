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
	var n, k int
	scan(&n, &k)
	var s string
	scan(&s)
	// tokens := regexp.MustCompile("W+").Split(s, -1)
	// for _, token := range tokens {
	// 	if len(token) >= k {
	// 		fmt.Println(0)
	// 		return
	// 	}
	// }

	var whitesInThisWindow = 0

	for i := 0; i < k; i++ {
		if s[i] == 'W' {
			whitesInThisWindow++
		}
	}
	var answer = whitesInThisWindow
	//debug("Before", answer)
	for i := k; i < n; i++ {
		if s[i-k] == 'W' {
			whitesInThisWindow--
		}
		if s[i] == 'W' {
			whitesInThisWindow++
		}

		if answer > whitesInThisWindow {
			answer = whitesInThisWindow
		}
		//debug("after ", i, whitesInThisWindow, answer)
	}
	fmt.Println(answer)
}

func main() {
	startTime := time.Now()

	defer flush()

	var ntc int = 1
	scan(&ntc)
	for t := 0; t < ntc; t++ {
		//debug("====================================", t, "====================================")
		solve()

	}

	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
