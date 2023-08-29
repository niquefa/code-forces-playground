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
	var n int
	scan(&n)
	var playerScore = make(map[string]int)
	var playerName = make([]string, n)
	var scored = make([]int, n)
	for i := 0; i < n; i++ {
		scan(&playerName[i], &scored[i])
		playerScore[playerName[i]] += scored[i]
	}
	var maxScore int = 0
	for _, v := range playerScore {
		if v >= maxScore {
			maxScore = v
		}
	}

	var possibleWinners = make(map[string]bool)
	for k, v := range playerScore {
		if v == maxScore {
			possibleWinners[k] = true
		}
	}
	playerScore = make(map[string]int)

	for i := 0; i < n; i++ {
		playerScore[playerName[i]] += scored[i]
		if playerScore[playerName[i]] >= maxScore && possibleWinners[playerName[i]] {
			fmt.Println(playerName[i])
			return
		}
	}
}

func main() {
	startTime := time.Now()

	defer flush()
	solve()

	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
