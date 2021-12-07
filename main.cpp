#include <iostream>
#include "lexer.h"


using std::cout;
using std::endl;

int main()
{
    Lexer lexer;
    string readfile = "test_program1.txt";

    lexer.set_readfile(readfile);

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