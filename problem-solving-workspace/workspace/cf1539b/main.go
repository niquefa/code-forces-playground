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
	var n, q, l, r int
	var s string
	scan(&n, &q, &s)

	s = "_" + s
	var count [26][100001]int

	for i := 1; i <= n; i++ {
		for j := 0; j < 26; j++ {
			count[j][i] = count[j][i-1]
		}
		count[s[i]-'a'][i]++
	}

	for i := 0; i < q; i++ {
		scan(&l, &r)
		var ans int64 = 0
		for j := 0; j < 26; j++ {
			if count[j][r]-count[j][l-1] > 0 {
				ans += int64(count[j][r]-count[j][l-1]) * (int64(j + 1))
			}
		}
		fmt.Println(ans)
	}
}

func main() {
	startTime := time.Now()

	defer flush()

	solve()

	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
