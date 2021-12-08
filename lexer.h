#ifndef __LEXER_H_INCLUDED__
#define __LEXER_H_INCLUDED__

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <exception>
#include <cctype>

using std::fstream;
using std::ifstream;
using std::ios;
using std::map;
using std::ostream;
using std::pair;
using std::string;

class Tag
{
public:
    static string AND, BASIC, BREAK, DO, ELSE, EQ, FALSE, GE, ID, IF, INDEX, LE, MINUS, NE, NUM, OR, REAL, TEMP, TRUE, WHILE;
};

class Token
{
public:
    string tag;
    string item;

    Token(string t, string i);
    Token(char t, string i);
    string toString();
};

class Word : public Token
{
public:
    string lexeme = "";
    static Word And, Or, eq, ne, le, ge, minus, True, False, temp;

    Word(string s, string tag);
    string toString();
};

class Type : public Word
{
public:
    int width = 0;
    static Type Int, Float, Char, Bool, Null;

    Type(string s, string tag, int w);
    static bool numeric(Type p);
    static Type max(Type p1, Type p2);
    friend bool operator==(Type &x, Type &y);
};

class Num : public Token
{
public:
    int value;

    Num(int v);
    string toString();
};

class Real : public Token
{
public:
    float value;

    Real(float v);
    string toString();
};

class MyException : public std::exception
{
public:
    string s;

    MyException(string ss) : s(ss) {}
    ~MyException() throw() {}
    const char *what() const throw() { return s.c_str(); }
};

class Lexer
{
public:
    static int line;

    Lexer();
    ~Lexer();
    void set_readfile(string filename);
    Token scan();

private:
    string readfile;
    ifstream fp;
    char peek = ' ';
    map<string, Word> words;

    void reserve(Word w);
    void readch();
    bool readch(char c);
};

#endif
