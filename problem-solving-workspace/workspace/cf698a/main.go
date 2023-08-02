package main

import (
	"bufio"
	"fmt"
	"os"
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

// Activity
// 0, if Vasya had a rest during the i-th day,
// 1, if Vasya participated in the contest on the i-th day,
// 2, if Vasya went to gym on the i-th day.
const ROWS int = 102
const COLS int = 3

var n int
var d = make([][]int, ROWS)
var a = make([]int, ROWS)

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

/*
f(day, activity) =

	Amount of days that Vasya can participate in a contest
	or go to gym from day 0 up to day "day" with the last activity "activity"
	i.e. the activity on day "day" is activity: 0 (rest), 1 (contest), or 2 (gym)

	So The answer is max between f(n-1, 0), f(n-1, 1), f(n-1, 2)
*/
func f(day, activity int) int {
	if day == 0 && activity == 0 { // base case, no days has pass, no activity
		return 0
	}
	if day == 0 && activity == 1 { // First day and we want to do contest
		if a[0] == 1 || a[0] == 3 {
			return 1 // We can do contest
		}
		return 0 // We can't do contest
	}
	if day == 0 && activity == 2 { // First day and we want to go to gym
		if a[0] == 2 || a[0] == 3 {
			return 1 // We can go to gym
		}
		return 0 // We can't go to gym
	}
	if d[day][activity] != -1 {
		return d[day][activity]
	}
	if activity == 0 {
		//If Vasya had a rest during the i-th day, the amount of days that Vasya
		//can participate in a contest or go to gym from day 0 up to day i-1
		//is max(f(i-1, 0), f(i-1, 1), f(i-1, 2)), so the answer is the max
		//of what he can achieve in the day before
		d[day][0] = max(f(day-1, 0), max(f(day-1, 1), f(day-1, 2)))
		return d[day][0]
	}
	answer := 0
	if activity == 1 {
		//If we want the answer for the i-th day to be "contest"
		//Vasya must have the option to do contest (a[i] == 1 or a[i] == 3)
		if a[day] == 1 || a[day] == 3 {
			answer = max(answer, f(day-1, 0))
			answer = max(answer, f(day-1, 2))
			d[day][1] = answer + 1
			return d[day][1]
		}
		//If Vasya can't do contest on this day, the answer is what he can achieve
		//on the day before and resting on this day
		answer = max(answer, f(day-1, 0))
	}
	if activity == 2 {
		//If we want the answer for the i-th day to be "gym"
		//Vasya must have the option to go to gym (a[i] == 2 or a[i] == 3)
		if a[day] == 2 || a[day] == 3 {
			answer = max(answer, f(day-1, 0))
			answer = max(answer, f(day-1, 1))
			d[day][2] = answer + 1
			return d[day][2]
		}
		//If Vasya can't go to gym on this day, the answer is what he can achieve
		//on the day before and resting on this day
		answer = max(answer, f(day-1, 0))
	}
	d[day][activity] = answer
	return d[day][activity]
}
func solve() {
	for i := range d {
		d[i] = make([]int, COLS)
	}
	for i := 0; i < ROWS; i++ {
		for j := 0; j < COLS; j++ {
			d[i][j] = -1
		}
	}
	scan(&n)
	for i := 0; i < n; i++ {
		scan(&a[i])
	}

	answer := 0
	answer = max(answer, f(n-1, 0))
	answer = max(answer, f(n-1, 1))
	answer = max(answer, f(n-1, 2))

	fmt.Println(n - answer)

}

// ----------------------------- TEMPLATE END ----------------------------------
// Dynamic programming memoization
func main() {
	defer flush()
	solve()
}
