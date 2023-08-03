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
func debug(a ...interface{})            { fmt.Fprintln(os.Stderr, a...) }
func assert(f bool) {
	if !f {
		panic("gg")
	}
}

func solve() {
	var exerciseAccumulator = [3]int{0, 0, 0}
	var exerciseName = [3]string{"chest", "biceps", "back"}
	var n int
	scan(&n)
	var tmp int
	for i := 0; i < n; i++ {
		scan(&tmp)
		exerciseAccumulator[i%3] += tmp
	}
	debug(exerciseAccumulator)
	var mostExercise = exerciseAccumulator[0]
	var mostExerciseIndex = 0
	for i := 0; i < 3; i++ {
		if mostExercise < exerciseAccumulator[i] {
			mostExercise = exerciseAccumulator[i]
			mostExerciseIndex = i
		}
	}
	printf("%s\n", exerciseName[mostExerciseIndex])

}

// ----------------------------- TEMPLATE END ----------------------------------

func main() {
	defer flush()
	solve()
}
