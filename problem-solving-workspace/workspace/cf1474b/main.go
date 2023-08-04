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
		panic("gg")
	}
}

func generatePrimes(n int) []int {
	composite := make([]bool, n+1)
	for i := 2; i*i <= n; i++ {
		if !composite[i] {
			for j := i * i; j <= n; j += i {
				composite[j] = true
			}
		}
	}

	var primes []int
	for p := 2; p <= n; p++ {
		if !composite[p] {
			primes = append(primes, p)
		}
	}
	return primes
}

func solve(primes []int) {
	var d int
	scan(&d)
	indexC := sort.Search(len(primes), func(i int) bool { return primes[i] >= d+1 })
	indexB := sort.Search(len(primes), func(i int) bool { return primes[i] >= d+primes[indexC] })
	fmt.Println(primes[indexC] * primes[indexB])
}

// ----------------------------- TEMPLATE END ----------------------------------
// sieve of eratosthenes number theory prime factorization
// Video explanation https://www.youtube.com/watch?v=CI4O7AxD9V8
func main() {
	start := time.Now()
	defer flush()
	primes := generatePrimes(200000)
	// for i, v := range primes {
	// 	debug(i, v)
	// }
	debug(len(primes), primes[len(primes)-1])
	var ntc int
	scan(&ntc)
	for t := 0; t < ntc; t++ {
		solve(primes)
	}
	elapsed := time.Since(start)
	debug("Running Time: ", elapsed)
}
