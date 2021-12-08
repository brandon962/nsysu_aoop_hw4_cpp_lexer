#include <iostream>
#include "lexer.h"

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char **argv)
{
    Lexer lexer;
    string readfile;

    if (argc > 1)
        readfile = argv[1];
    else
    {
        cout << "while file want to scan: ";
        cin >> readfile;
    }

    std::ifstream file(readfile);
    if (file.good())
        lexer.set_readfile(readfile);
    else
    {
        cout << "File not find, scan \"test_program1.txt\"." << endl;
        lexer.set_readfile("test_program1.txt");
    }

    try
    {
        while (true)
        {
            Token t = lexer.scan();
            cout << t.toString() << endl;
        }
    }
    catch (MyException &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}