package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
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
var levelToSticks []int64

func solve() {
	var n int64
	scan(&n)
	var ans int64
	for {
		if n <= 0 {
			break
		}
		index := sort.Search(len(levelToSticks), func(i int) bool { return levelToSticks[i] > n })

		if index > 1 && index < len(levelToSticks) {
			n -= levelToSticks[index-1]
			if n >= 0 {
				ans++
			}
		} else {
			break
		}
	}

	fmt.Println(ans)
}
func cardsForPyramidOfHigh(n int64) int64 {
	return (n * (n + 1)) / 2
}

// Sorting binary search
func main() {
	startTime := time.Now()

	defer flush()
	var n int64
	levelToSticks = append(levelToSticks, 0)
	for n = 1; ; n++ {
		sticks := 3*cardsForPyramidOfHigh(n) - n
		if sticks > 10e9 {
			break
		}
		levelToSticks = append(levelToSticks, sticks)
	}
	for k, v := range levelToSticks {
		debug(k, v)
		if k > 20 {
			break
		}
	}
	debug("Total levels:", len(levelToSticks))
	var ntc int
	scan(&ntc)
	for t := 0; t < ntc; t++ {

		solve()

	}

	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
