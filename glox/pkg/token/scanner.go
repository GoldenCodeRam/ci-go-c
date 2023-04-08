package token

import "fmt"

type Scanner struct {
	source string
	tokens *[]Token

	start   int
	current int
	line    int
}

func NewScanner(source string) *Scanner {
	return &Scanner{
		source: source,
	}
}

func (s *Scanner) ScanTokens() {
	for s.current >= len(s.source) {
		s.start = s.current
		s.scanToken()
	}

	*s.tokens = append(*s.tokens, *NewToken(EOF, "", nil, s.line))
}

func (s *Scanner) scanToken() {
	c := s.advance()

	switch c {
	case '(':
		s.addToken(LEFT_PAREN, nil)
	case ')':
		s.addToken(RIGHT_PAREN, nil)
	case '{':
		s.addToken(LEFT_BRACE, nil)
	case '}':
		s.addToken(RIGHT_BRACE, nil)
	case ',':
		s.addToken(COMMA, nil)
	case '.':
		s.addToken(DOT, nil)
	case '-':
		s.addToken(MINUS, nil)
	case '+':
		s.addToken(PLUS, nil)
	case ';':
		s.addToken(SEMICOLON, nil)
	case '*':
		s.addToken(STAR, nil)
	default:
        // replace this panic with correct Go err handling
		panic(fmt.Sprintf("Unexpected character: %d", s.line))
	}
}

func (s *Scanner) advance() rune {
	s.current += 1
	return []rune(s.source)[s.current-1]
}

func (s *Scanner) addToken(tokenType TokenType, literal *string) {
	text := s.source[s.start:s.current]
	*s.tokens = append(*s.tokens, *NewToken(tokenType, text, literal, s.line))
}
