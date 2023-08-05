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
		panic("gg Rafa, something went wrong!")
	}
}

// ----------------------------- TEMPLATE END ----------------------------------
var almostPrimes = make([]int, 0)

func getAllDivisors(n int) []int {
	var result []int
	for i := 1; i <= n; i++ {
		if n%i == 0 {
			result = append(result, i)
		}
	}
	return result
}
func isPrime(n int) bool {
	if n < 2 {
		return false
	}
	for i := 2; i*i <= n; i++ {
		if n%i == 0 {
			return false
		}
	}
	return true
}
func isAlmostPrime(n int) bool {
	var divisors = getAllDivisors(n)
	var primeDivisors int = 0
	for _, d := range divisors {
		if d != 1 && d != n && isPrime(d) {
			primeDivisors++
		}
	}
	return primeDivisors == 2
}

func solve() {
	var n int
	scan(&n)
	var result int = 0
	for i := 0; i < len(almostPrimes); i++ {
		if almostPrimes[i] <= n {
			result++
		}
	}
	fmt.Println(result)
}

func main() {
	for i := 3; i <= 3000; i++ {
		if isAlmostPrime(i) {
			almostPrimes = append(almostPrimes, i)
		}
	}
	defer flush()
	solve()
}
