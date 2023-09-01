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
	var a = make([]int, n)
	for i := 0; i < n; i++ {
		scan(&a[i])
	}
	var alice, bob, total int
	var aliceIndex, bobIndex int = 0, n - 1
	var aliceLast, bobLast int = 0, 0
	var aliceTurn bool = true
	var indexUsed = make(map[int]bool)
	for len(indexUsed) < n {
		if aliceTurn {
			if indexUsed[aliceIndex] {
				break
			}
			total++
			if aliceIndex == 0 {
				indexUsed[aliceIndex] = true
				aliceLast = a[aliceIndex]
				alice += a[aliceIndex]
				aliceIndex++
			} else {
				aliceLast = a[aliceIndex]
				alice += a[aliceIndex]
				indexUsed[aliceIndex] = true
				aliceIndex++
				for aliceLast <= bobLast && aliceIndex < n && !indexUsed[aliceIndex] {

					aliceLast += a[aliceIndex]
					alice += a[aliceIndex]
					indexUsed[aliceIndex] = true
					aliceIndex++
					if aliceLast > bobLast {
						break
					}
				}
			}
			if indexUsed[aliceIndex] {
				break
			}
		} else {
			if indexUsed[bobIndex] {
				break
			}
			bobLast = a[bobIndex]
			bob += a[bobIndex]
			indexUsed[bobIndex] = true
			bobIndex--
			total++
			for bobLast <= aliceLast && bobIndex >= 0 && !indexUsed[bobIndex] {
				bobLast += a[bobIndex]
				bob += a[bobIndex]
				indexUsed[bobIndex] = true

				bobIndex--
				if bobLast > aliceLast {
					break
				}
			}
			if indexUsed[bobIndex] {
				break
			}
		}
		aliceTurn = !aliceTurn
	}

	fmt.Println(total, alice, bob)
}

func main() {
	startTime := time.Now()

	defer flush()

	var ntc int = 1
	scan(&ntc)
	for t := 0; t < ntc; t++ {
		debug("\n====================================", t, "====================================")
		solve()
	}

	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
