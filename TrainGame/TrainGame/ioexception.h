#ifndef IOEXCEPTION_H
#define IOEXCEPTION_H

#include "gameexception.h"

/**
 * @brief IoException class inherited from GameException. Descbribes exception for IO
 */
class IoException : public GameException
{
public:
    explicit IoException(const QString& msg = "");
    virtual ~IoException() = default;
};

#endif // IOEXCEPTION_H
