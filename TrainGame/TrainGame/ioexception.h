#ifndef IOEXCEPTION_H
#define IOEXCEPTION_H

#include "gameexception.h"

class IoException : public GameException
{
public:
    explicit IoException(const QString& msg = "");
    virtual ~IoException() = default;
};

#endif // IOEXCEPTION_H
