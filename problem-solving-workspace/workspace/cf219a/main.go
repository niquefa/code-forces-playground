package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
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
func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
func solve() {
	var k int
	var s string
	scan(&k, &s)
	frequencyTable := make(map[byte]int)
	for i := 0; i < len(s); i++ {
		frequencyTable[s[i]]++
	}
	if k > len(s) {
		fmt.Println(-1)
		return
	}
	if k == len(s) {
		if len(frequencyTable) == 1 {
			fmt.Println(s)
		} else {
			fmt.Println(-1)
		}
		return
	}
	if len(s)%k != 0 {
		fmt.Println(-1)
		return
	}

	var ans string
	for letter, v := range frequencyTable {
		if v%k != 0 {
			fmt.Println(-1)
			return
		}
		for i := 0; i < v/k; i++ {
			ans += string(letter)
		}
	}

	fmt.Println(strings.Repeat(ans, k))
}

func main() {
	startTime := time.Now()

	defer flush()

	var ntc int = 1
	//scan(&ntc)
	for t := 0; t < ntc; t++ {

		solve()

	}

	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
