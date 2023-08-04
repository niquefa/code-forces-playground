package main

import (
	"bufio"
	"container/list"
	"fmt"
	"os"
	"strings"
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
	var s string
	scan(&s)
	l := list.New()
	for _, c := range s {
		l.PushFront(c)
		l.PushBack(c)
	}
	var ans strings.Builder
	for e := l.Front(); e != nil; e = e.Next() {
		ans.WriteRune(e.Value.(rune))
	}
	fmt.Println(ans.String())
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
