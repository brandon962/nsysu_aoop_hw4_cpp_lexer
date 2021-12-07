#ifndef __LEXER_H_INCLUDED__
#define __LEXER_H_INCLUDED__

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <exception>

using std::map;
using std::string;
using std::pair;
using std::ifstream;
using std::ostream;
using std::fstream;
using std::ios;

class Tag
{
public:
    static const int AND = 256;
    static const int BASIC = 257;
    static const int BREAK = 258;
    static const int DO = 259;
    static const int ELSE = 260;
    static const int EQ = 261;
    static const int FALSE = 262;
    static const int GE = 263;
    static const int ID = 264;
    static const int IF = 265;
    static const int INDEX = 266;
    static const int LE = 267;
    static const int MINUS = 268;
    static const int NE = 269;
    static const int NUM = 270;
    static const int OR = 271;
    static const int REAL = 272;
    static const int TEMP = 273;
    static const int TRUE = 274;
    static const int WHILE = 275;
};

class Token
{
public:
    int tag;

    Token(int t);
    string toString();
};

class Word : public Token
{
public:
    string lexeme = "";
    static Word And, Or, eq, ne, le, ge, minus, True, False, temp;

    Word(string s, int tag);
    string toString();
};

class Type : public Word
{
public:
    int width = 0;
    static Type Int, Float, Char, Bool, Null;

    Type(string s, int tag, int w);
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

    MyException(string ss) : s(ss){}
    ~MyException() throw () {}
    const char* what() const throw() {return s.c_str();}
};

class Lexer
{
public:
    static int line;

    Lexer();
    ~Lexer();
    void set_readfile(string filename);

private:
    string readfile;
    ifstream fp;
    char peek = ' ';
    map<string, Word> words;
    
    void reserve(Word w);
    void readch();
    bool readch(char c);
    Token scan();
};

#endif
