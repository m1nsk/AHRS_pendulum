#ifndef PARSEEXCEPTION_H
#define PARSEEXCEPTION_H
#include <exception>
using namespace std;

class ParseException : public exception
{
    virtual const char* what() const throw()
    {
        return "Parse fail";
    }
};

#endif // PARSEEXCEPTION_H
