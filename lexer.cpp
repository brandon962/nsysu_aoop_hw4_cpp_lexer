#include "lexer.h"

// CLASS TOKEN ------------------------------------
Token::Token(int t) { tag = t; }

string Token::toString() { return std::to_string(tag); }

// CLASS WORD -------------------------------------
Word::Word(string s, int tag) : Token(tag) { lexeme = s; }

string Word::toString() {return lexeme;}

Word Word::And = Word("&&", Tag::AND);
Word Word::Or = Word("||", Tag::OR);
Word Word::eq = Word("==", Tag::EQ);
Word Word::ne = Word("!=", Tag::NE);
Word Word::le = Word("<=", Tag::LE);
Word Word::ge = Word(">=", Tag::GE);
Word Word::minus = Word("minus", Tag::MINUS);
Word Word::True = Word("true", Tag::TRUE);
Word Word::False = Word("false", Tag::FALSE);
Word Word::temp = Word("t", Tag::TEMP);
// CLASS LEXER ------------------------------------
int Lexer::line = 1;
Lexer::Lexer()
{
}

Lexer::~Lexer() {}

void Lexer::reserve(Word w)
{
}