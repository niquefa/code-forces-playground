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
type GameResult struct {
	alice, bob int
}

var cache map[string]GameResult

func allZeros(s string) bool {
	for i := 0; i < len(s); i++ {
		if s[i] != '0' {
			return false
		}
	}
	return true
}

func allOnes(s string) bool {
	for i := 0; i < len(s); i++ {
		if s[i] != '1' {
			return false
		}
	}
	return true
}

// memoization solution with recursion takes too much time, get TLE
func f(s string, aliceTurn bool) GameResult {
	if len(s) == 0 || allZeros(s) {
		return GameResult{0, 0}
	}
	if allOnes(s) {
		if aliceTurn {
			return GameResult{len(s), 0}
		} else {
			return GameResult{0, len(s)}
		}
	}

	if v, ok := cache[s]; ok {
		return v
	}
	aliceBestScore := 0
	bobBestScore := 0
	for i := 0; i < len(s); {
		if s[i] == '0' {
			i++
			continue
		}
		var j int
		for j = i; j < len(s); j++ {
			if s[j] == '0' {
				break
			}
		}
		aliceScore := 0
		bobScore := 0
		if aliceTurn {
			aliceScore = j - i
		} else {
			bobScore = j - i
		}

		nextTurn := f(s[:i]+s[j:], !aliceTurn)
		if aliceTurn {
			if aliceScore+nextTurn.alice > aliceBestScore {
				aliceBestScore = aliceScore + nextTurn.alice
				bobBestScore = nextTurn.bob
			}
		} else {
			if bobScore+nextTurn.bob > bobBestScore {
				bobBestScore = bobScore + nextTurn.bob
				aliceBestScore = nextTurn.alice
			}
		}
		i = j + 1

	}
	cache[s] = GameResult{aliceBestScore, bobBestScore}
	return GameResult{aliceBestScore, bobBestScore}
}

func nextTurn(s string) (int, string) {
	bestFirstIndex := -1
	bestSecondIndex := -1
	bestScore := 0
	for i := 0; i < len(s); {
		if s[i] == '0' {
			i++
			continue
		}
		var j int
		for j = i; j < len(s); j++ {
			if s[j] == '0' {
				break
			}
		}
		nextStep := s[:i] + s[j:]
		score := len(s) - len(nextStep)
		if score > bestScore {
			bestScore = score
			bestFirstIndex = i
			bestSecondIndex = j
		}
		i = j + 1
	}
	if bestFirstIndex == -1 || bestSecondIndex == -1 {
		return 0, ""
	}
	return bestScore, s[:bestFirstIndex] + s[bestSecondIndex:]
}
func countOnes(s string) int {
	count := 0
	for i := 0; i < len(s); i++ {
		if s[i] == '1' {
			count++
		}
	}
	return count
}
func solve() {
	var s string
	scan(&s)
	//cache = make(map[string]GameResult)
	//bestResults := f(s, true)
	//fmt.Println(bestResults.alice)
	aliceScore := 0
	aliceTurn := true
	if len(s) == 0 || allZeros(s) || allOnes(s) {
		fmt.Println(countOnes(s))
		return
	}
	for {
		score, nextTurn := nextTurn(s)
		if aliceTurn {
			aliceScore += score
		}
		if len(nextTurn) == 0 {
			break
		}
		s = nextTurn
		aliceTurn = !aliceTurn
	}
	fmt.Println(aliceScore)
}

func main() {
	startTime := time.Now()

	defer flush()

	var ntc int
	scan(&ntc)
	for t := 0; t < ntc; t++ {
		debug("test", t)
		solve()

	}

	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
