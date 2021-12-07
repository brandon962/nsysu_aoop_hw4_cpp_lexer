#include <iostream>
#include <exception>
#include "lexer.h"

using namespace std;

int main()
{
    map<string, string> w;
    w.insert(pair<string, string>("1","123"));
    cout << w.find("1")->first << endl;
    cout << (("1")[w]) << endl;
    
    return 0;
}