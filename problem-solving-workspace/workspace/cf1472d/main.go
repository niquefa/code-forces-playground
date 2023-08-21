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

func solve() {
	var n int
	scan(&n)
	var even []int
	var odd []int
	var evenSum = 0
	var oddSum = 0
	for i := 0; i < n; i++ {
		var tmp int
		scan(&tmp)
		if tmp%2 == 0 {
			evenSum += tmp
			even = append(even, tmp)
		} else {
			oddSum += tmp
			odd = append(odd, tmp)
		}
	}
	if n == 1 && evenSum == 0 {
		fmt.Println("Tie")
		return
	}
	if n == 1 && oddSum == 0 {
		fmt.Println("Alice")
		return
	}
	if evenSum == 0 {
		fmt.Println("Bob")
		return
	}
	if oddSum == 0 {
		fmt.Println("Alice")
		return
	}
	sort.Sort(sort.Reverse(sort.IntSlice(even)))
	sort.Sort(sort.Reverse(sort.IntSlice(odd)))

	var aliceTurn = true
	var aliceSum = 0
	var bobSum = 0
	var evenIndex = 0
	var oddIndex = 0
	for evenIndex < len(even) || oddIndex < len(odd) {
		if aliceTurn {
			if evenIndex < len(even) && oddIndex < len(odd) {
				if even[evenIndex] >= odd[oddIndex] {
					aliceSum += even[evenIndex]
					evenIndex++
				} else {
					oddIndex++
				}
			} else if evenIndex < len(even) {
				aliceSum += even[evenIndex]
				evenIndex++
			} else {
				oddIndex++
			}
		} else {
			if evenIndex < len(even) && oddIndex < len(odd) {
				if even[evenIndex] <= odd[oddIndex] {
					bobSum += odd[oddIndex]
					oddIndex++
				} else {
					evenIndex++
				}
			} else if evenIndex < len(even) {
				evenIndex++
			} else {
				bobSum += odd[oddIndex]
				oddIndex++
			}
		}

		aliceTurn = !aliceTurn
	}
	debug(n, even, odd, evenSum, oddSum)
	debug(aliceSum, bobSum)
	if aliceSum > bobSum {
		fmt.Println("Alice")
	} else if bobSum > aliceSum {
		fmt.Println("Bob")
	} else {
		fmt.Println("Tie")
	}
}

func main() {
	startTime := time.Now()

	defer flush()

	var ntc int = 1
	scan(&ntc)
	for t := 0; t < ntc; t++ {

		solve()

	}

	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
