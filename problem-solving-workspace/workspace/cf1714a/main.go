package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func flush()                            { out.Flush() }
func scan(a ...interface{})             { fmt.Fscan(in, a...) }
func printf(f string, a ...interface{}) { fmt.Fprintf(out, f, a...) }
func assert(f bool) {
	if !f {
		panic("gg")
	}
}

type Time struct {
	hours   int
	minutes int
}

func nextMinute(h, m int) (int, int) {
	m++
	if m == 60 {
		m = 0
		h++
		if h == 24 {
			h = 0
		}
	}
	return h, m
}
func minutesToHoursAndMinutes(m int) (int, int) {
	return m / 60, m % 60
}
func solve() {
	var n, H, M, h, m int
	scan(&n, &H, &M)
	var t = make([]Time, n)
	for i := 0; i < n; i++ {
		scan(&h, &m)
		t[i] = Time{h, m}
	}
	sort.Slice(t, func(i, j int) bool {
		if t[i].hours == t[j].hours {
			return t[i].minutes < t[j].minutes
		}
		return t[i].hours < t[j].hours
	})
	// fmt.Printf("TIMES H %d M %d\n", H, M)
	// for _, t := range t {
	// 	fmt.Printf("(%d, %d)\n", t.hours, t.minutes)
	// }
	for _, t := range t {
		if H == t.hours && M == t.minutes {
			fmt.Println("0 0")
			return
		}
	}
	currentMinute := M
	currentHour := H
	minutesSleeping := 0
	for {
		currentHour, currentMinute = nextMinute(currentHour, currentMinute)
		minutesSleeping++
		for _, t := range t {
			if currentHour == t.hours && currentMinute == t.minutes {
				h, m := minutesToHoursAndMinutes(minutesSleeping)
				fmt.Println(h, m)
				return
			}
		}
	}
}

// ----------------------------- TEMPLATE END ----------------------------------

func main() {
	defer flush()

	var ntc int
	scan(&ntc)
	for t := 0; t < ntc; t++ {
		solve()
	}
}
