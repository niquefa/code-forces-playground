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
	var px, py int
	scan(&px, &py)
	var s string
	scan(&s)
	const D = "UDLR"
	directions := make(map[byte]int)
	for i := 0; i < len(s); i++ {
		directions[s[i]]++
	}
	for i := 0; i < len(D); i++ {
		debug(D[i], directions[D[i]])
	}
	if px == 0 {
		if py > 0 {
			if directions['U'] >= py {
				printf("YES\n")
			} else {
				printf("NO\n")
			}
		} else {
			if directions['D'] >= -py {
				printf("YES\n")
			} else {
				printf("NO\n")
			}
		}
		return
	}
	if py == 0 {
		if px > 0 {
			if directions['R'] >= px {
				printf("YES\n")
			} else {
				printf("NO\n")
			}
		} else {
			if directions['L'] >= -px {
				printf("YES\n")
			} else {
				printf("NO\n")
			}
		}
		return
	}
	if px > 0 && py > 0 {
		if directions['R'] >= px && directions['U'] >= py {
			printf("YES\n")
		} else {
			printf("NO\n")
		}
		return
	}
	if px > 0 && py < 0 {
		if directions['R'] >= px && directions['D'] >= -py {
			printf("YES\n")
		} else {
			printf("NO\n")
		}
		return
	}
	if px < 0 && py > 0 {
		if directions['L'] >= -px && directions['U'] >= py {
			printf("YES\n")
		} else {
			printf("NO\n")
		}
		return
	}
	if px < 0 && py < 0 {
		if directions['L'] >= -px && directions['D'] >= -py {
			printf("YES\n")
		} else {
			printf("NO\n")
		}
		return
	}
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
