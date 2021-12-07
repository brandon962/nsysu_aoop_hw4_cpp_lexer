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
        std::cout << "Error: in class Type in max function return null" << std::endl;
        return Type::Null;
    }
    else if (p1 == Type::Float || p2 == Type::Float)
        return Type::Float;
    else if (p1 == Type::Int || p2 == Type::Int)
        return Type::Int;
    else
        return Type::Char;
}

Type Type::Int = Type("int", Tag::BASIC, 4);
Type Type::Float = Type("float", Tag::BASIC, 8);
Type Type::Char = Type("char", Tag::BASIC, 1);
Type Type::Bool = Type("bool", Tag::BASIC, 1);
Type Type::Null = Type("null", Tag::BASIC, 1);
// CLASS NUM --------------------------------------
Num::Num(int v) : Token(Tag::NUM) { value = v; }

string Num::toString() { return std::to_string(value); }

// CLASS REAL -------------------------------------
Real::Real(float v) : Token(Tag::REAL) { value = v; }

string Real::toString() { return std::to_string(value); }

// CLASS LEXER ------------------------------------
int Lexer::line = 1;
Lexer::Lexer()
{
    reserve(Word("if", Tag::IF));
    reserve(Word("else", Tag::ELSE));
    reserve(Word("while", Tag::WHILE));
    reserve(Word("do", Tag::DO));
    reserve(Word("break", Tag::BREAK));
    reserve(Word::True);
    reserve(Word::False);
    reserve(Type::Int);
    reserve(Type::Char);
    reserve(Type::Bool);
    reserve(Type::Float);
    reserve(Type::Null);
}

Lexer::~Lexer() { fp.close(); }

void Lexer::set_readfile(string filename)
{
    readfile = filename;
    fp.open(readfile, ios::in);
}

void Lexer::reserve(Word w) { words.insert(std::pair<string, Word>(w.lexeme, w)); }

void Lexer::readch()
{
    char c;
    fp.get(c);
    if (c)
        peek = c;
    else
        throw MyException("End of file readched");
}

bool Lexer::readch(char c)
{
    readch();
    if (peek != c)
        return false;
    peek = ' ';
    return true;
}

Token Lexer::scan()
{
    for (;; readch())
    {
        if (peek == ' ' || peek == '\t')
            continue;
        else if (peek == '\n')
            ++line;
        else
            break;
    }
    switch (peek)
    {
    case '&':
        if (readch('&'))
            return Word::And;
        else
            return Token('&');
    case '|':
        if (readch('|'))
            return Word::Or;
        else
            return Token('|');
    case '=':
        if (readch('='))
            return Word::eq;
        else
            return Token('=');
    case '!':
        if (readch('='))
            return Word::ne;
        else
            return Token('!');
    case '<':
        if (readch('='))
            return Word::le;
        else
            return Token('<');
    case '>':
        if (readch('='))
            return Word::ge;
        else
            return Token('>');
    }

    if (isdigit(peek))
    {
        int v = 0;
        do
        {
            v = 10 * v + isdigit(peek);
            readch();
        } while (isdigit(peek));
        if (peek != '.')
            return Num(v);
        float x = v;
        float d = 10;
        for (;;)
        {
            readch();
            if (!isdigit(peek))
                break;
            x += (peek - '0') / d;
            d *= 10;
        }
        return Real(x);
    }

    if (isalpha(peek))
    {
        string b = "";
        do
        {
            b += peek;
            readch();
        } while (isalnum(peek));

        auto iter = words.find(b);
        if (iter != words.end())
            return iter->second;
        Word w = Word(b, Tag::ID);
        words.insert(pair<string, Word>(b, w));
        return w;
    }

    Token tok = Token(peek);
    peek = ' ';
    return tok;
}