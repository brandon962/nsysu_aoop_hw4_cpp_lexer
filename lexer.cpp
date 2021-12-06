#include "lexer.h"

// CLASS TOKEN ------------------------------------
Token::Token(int t) { tag = t; }

string Token::toString() { return std::to_string(tag); }

// CLASS WORD -------------------------------------
Word::Word(string s, int tag) : Token(tag) { lexeme = s; }

string Word::toString() { return lexeme; }

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

// class TYPE -------------------------------------
Type::Type(string s, int tag, int w) : Word(s, tag) { width = w; }

bool operator==(Type &x, Type &y)
{
    if (x.width == y.width && x.lexeme == y.lexeme && x.tag == y.tag)
        return true;
    return false;
}

bool Type::numeric(Type p)
{
    if (p == Type::Char || p == Type::Int || p == Type::Float)
        return true;
    else
        return false;
}

Type Type::max(Type p1, Type p2)
{
    if (!numeric(p1) || !numeric(p2))
    {
        std::cerr << "Error: in class Type in max function return null" << std::endl;
        return Type::Null;
    }
    else
        return Type::Char;
}

Type Type::Int = Type("int", Tag::BASIC, 4);
Type Type::Float = Type("float", Tag::BASIC, 8);
Type Type::Char = Type("char", Tag::BASIC, 1);
Type Type::Bool = Type("bool", Tag::BASIC, 1);
Type Type::Null = Type("null", Tag::BASIC, 1);
// CLASS LEXER ------------------------------------
int Lexer::line = 1;
Lexer::Lexer()
{
}

Lexer::~Lexer() {}

void Lexer::reserve(Word w)
{
}