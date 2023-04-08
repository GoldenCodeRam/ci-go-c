package main

import (
	"fmt"
	"os"

	token "github.com/goldencoderam/pkg/token"
)

func main() {
    args := os.Args

    if len(args) > 1 {
        panic("Usage: glox [script]")
    } else if len(args) == 2 {
        runFile(args[1])
    } else {
        runPrompt()
    }
}

func runFile(filePath string) {
    bytes, err := os.ReadFile(filePath)

    if err != nil {
        panic(err)
    }

    run(string(bytes))
}

func runPrompt() {
    for {
        var input string
        fmt.Print("> ")
        _, err := fmt.Scan(&input)

        if err != nil {
            panic(err)
        }

        run(input)
    }
}

func run(source string) {
    var tokens []token.Token

    scanner := token.NewScanner(source)
    scanner.ScanTokens()

    for token := range tokens {
        fmt.Println(token)
    }
}

func error(line int, message string) {
    report(line, "", message)
}

func report(line int, where string, message string) {
    fmt.Printf("[Line %d] Error %s: %s", line, where, message)
}
