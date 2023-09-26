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
var numbers []int64

func solve() {
	var n int
	scan(&n)
	for i := 0; i < n; i++ {
		fmt.Print(numbers[i+3], " ")
	}
	fmt.Println()

}
func isSorted(arr []int64) bool {
	for i := 0; i < len(arr)-1; i++ {
		if arr[i] > arr[i+1] {
			return false
		}
	}
	return true
}
func main() {
	startTime := time.Now()
	numbers = append(numbers, 3)
	numbers = append(numbers, 4)
	for i := 2; len(numbers) < 200100; i++ {
		sum := numbers[i-1] + numbers[i-2]
		candidate := numbers[i-1] + 1
		if (3*candidate)%sum == 0 {
			candidate = candidate + sum - (3*candidate)%sum
		}
		numbers = append(numbers, candidate)
	}
	for i := 4; i < len(numbers); i++ {
		sum := numbers[i-1] + numbers[i-2]
		if (3*numbers[i])%sum == 0 {
			debug("ERROR ", i)
			fmt.Println("ERROR MF")
		}
	}
	debug("MAX ", numbers[len(numbers)-1], isSorted(numbers))
	defer flush()

	var ntc int = 1
	scan(&ntc)
	for t := 0; t < ntc; t++ {
		solve()
	}

	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
