#ifndef ILLEGALARGUMENTEXCEPTION_H
#define ILLEGALARGUMENTEXCEPTION_H

#include <iostream>
#include <exception>

class IllegalArgumentException: public std::exception {
public:
    const char * what () const throw () {
        return "Error: illegal argument.";
    }
};

#endif
