#include <iostream>
#include <exception>

using namespace std;

int main()
{

    class MyException : public std::exception
    {
    public:
        string s;

        MyException(string ss) : s(ss) {}
        ~MyException() throw() {}
        const char *what() const throw() { return s.c_str(); }
    };

    try
    {
        throw MyException("End of file readched");
    }
    catch (MyException &caught)
    {
        std::cout << "Got " << caught.what() << std::endl;
    }

    return 0;
}