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
func bruteForce(a []int, l, r int) int {
	var ans int
	debug(a, l, r, len(a))
	for i := 0; i < len(a); i++ {
		for j := i + 1; j < len(a); j++ {
			if l <= a[i]+a[j] && a[i]+a[j] <= r {
				debug(i, j, a[i], a[j], a[i]+a[j])
				ans++
			}
		}
	}
	return ans
}
func solve() {
	var n, l, r int
	scan(&n, &l, &r)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		scan(&a[i])
	}

	sort.Ints(a)

	var ans int64 = 0
	//debug("\nTest case", n, l, r)
	//debug(a)
	for i := 0; i < n; i++ {
		// Find the index where a[j] <= r - a[i]
		// Find the smallest index "upper" for which a[upper] >= r - a[i] + 1.
		// The count of elements that can be paired with a[i] to make
		// a[i] + a[j] <= r is upper - i - 1 (if i < upper).
		upper := sort.SearchInts(a, r-a[i]+1)

		// Find the index where a[j] >= l - a[i]
		// Find the smallest index "lower" for which a[lower] >= l - a[i].
		// The count of elements that can be paired with a[i] to make a[i] + a[j] >= l is the length of the array minus lower minus 1 (if i >= lower).
		lower := sort.SearchInts(a, l-a[i])
		//debug(i, a[i], upper, lower, upper-lower)
		ans += int64(upper - lower)

		// Special case handling for the pair (i, i).
		if l <= 2*a[i] && 2*a[i] <= r {
			ans--
			//debug("Special case", i, a[i])
		}
	}
	// Divide the answer by 2 as each pair is counted twice.
	ans /= 2
	printf("%d\n", ans)
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
