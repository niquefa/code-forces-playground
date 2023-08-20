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
func isPalindrome(s string) bool {
	n := len(s)
	for i := 0; i < n/2; i++ {
		if s[i] != s[n-i-1] {
			return false
		}
	}
	return true
}
func canBecomePalindrome(s string) bool {
	var frequencies = make(map[rune]int)
	for _, c := range s {
		frequencies[c]++
	}
	oddCount := 0
	for _, v := range frequencies {
		if v%2 == 1 {
			oddCount++
			if oddCount > 1 {
				return false
			}
		}
	}
	return true
}
func canBecomePalindromeF(frequencies map[rune]int) bool {

	oddCount := 0
	for _, v := range frequencies {
		if v%2 == 1 {
			oddCount++
			if oddCount > 1 {
				return false
			}
		}
	}
	return true
}
func solve() {
	var s string
	scan(&s)
	if isPalindrome(s) || canBecomePalindrome(s) {
		fmt.Println("First")
		return
	}
	var f = make(map[rune]int)
	for _, c := range s {
		f[c]++
	}
	var first bool = true
	for {
		if canBecomePalindromeF(f) {
			if first {
				fmt.Println("First")
			} else {
				fmt.Println("Second")
			}
			return
		}
		var change bool = false
		for k, v := range f {
			if v > 0 && v%2 == 0 {
				f[k]--
				change = true
				break
			}
		}
		if !change {
			for k, v := range f {
				if v > 0 && v%2 == 1 {
					f[k]--
					change = true
					break
				}
			}
		}
		//fmt.Println(f)
		first = !first
	}

}

func main() {
	startTime := time.Now()

	defer flush()
	solve()

	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
