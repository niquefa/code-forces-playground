package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
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
	var sa, sb string
	scan(&sa, &sb)
	x := strings.ReplaceAll(sa, "0", "")
	y := strings.ReplaceAll(sb, "0", "")
	isa, _ := strconv.Atoi(sa)
	isb, _ := strconv.Atoi(sb)
	z := strings.ReplaceAll(strconv.Itoa(isa+isb), "0", "")
	ix, _ := strconv.Atoi(x)
	iy, _ := strconv.Atoi(y)
	iz, _ := strconv.Atoi(z)

	if ix+iy == iz {
		printf("YES\n")
	} else {
		printf("NO\n")
	}

}

func main() {
	startTime := time.Now()

	defer flush()

	solve()

	debug(fmt.Sprintf("\n\t\t>>> %s EXECUTION TIME <<<\n", time.Since(startTime)))
}
