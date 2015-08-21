#ifndef MYEXCEPTIONS_H
#define MYEXCEPTIONS_H

#include <iostream>
#include <exception>


class MyExceptions
{
    public:
        MyExceptions();

       virtual ~MyExceptions();
//       std::string edgeInsufficency() const throw();


    protected:
    private:
    int x;

};

#endif // MYEXCEPTIONS_H
